/*
	This routine is only a example to perform a XCP CONNECT
	to an connected SLAVE on a configured (IP settings) network.
*/


#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

#include "xcpd.h"

#define SRC_PORT		5555
#define DST_PORT		5555
#define ECU_IP			"127.0.0.1"
#define SEEDNKEYXCP_SO		"SeedNKeyXCP.so"


int main(int argc, char *argv[])
{
	int s;
	struct sockaddr_in servaddr, srcaddr;
	std::vector<uint8_t> data = { 0x11, 0x22, 0x33, 0x44 };

	XCPMsgPtr connect_message, GetStatus, GetSeed1, SetMTA;
	XCPMsgPtr Upload, ShortUpload, Download, ShortDownload, disconnect_message;


	LoadSO(); // Loads the user provided dll with the Seed&Key algorithms. Sets up the GetAvailablePrivileges and ComputeKeyFromSeed function pointers.
	master = new XCPMaster(TransportLayer::ETHERNET);
	master->SetSeedAndKeyFunctionPointers(
		GetAvailablePrivileges,		// function pointer for the GetAvailablePrivileges
		ComputeKeyFromSeed);		// function pointer for the ComputeKeyFromSeed

	// Creating socket file descriptor
	if ( (s = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Filling client information
	memset(&srcaddr, 0, sizeof(srcaddr));
	srcaddr.sin_family = AF_INET;
	srcaddr.sin_addr.s_addr= htonl(INADDR_ANY);
	srcaddr.sin_port = htons(SRC_PORT);
	bind(s, (struct sockaddr *) &srcaddr, sizeof(srcaddr));

	// Filling server information
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(DST_PORT);
	servaddr.sin_addr.s_addr = inet_addr(ECU_IP);

	// perform XCP
	// ################################### CONNECT ##########################################
	std::cout << "Send XCP CONNECT.\n";
	connect_message = master->CreateConnectMessage(ConnectPacket::ConnectMode::NORMAL);
	Send(s, servaddr, std::move(connect_message));
	MaxRecvsize = master->GetSlaveProperties().MaxDto;
	std::cout << "\n";

	// ################################# GET STATUS #########################################
	std::cout << "Send XCP GET_STATUS.\n";
	GetStatus = master->CreateGetStatusMessage();
	Send(s, servaddr, std::move(GetStatus));
	std::cout << "\n";

	// unlook SLAVE with calculated key
	std::cout << "Send to get seed.\n";
	GetSeed1 = master->CreateGetSeedMessage(GetSeedPacket::Mode::FIRST_PART, GetSeedPacket::Resource::DAQ);
	Send(s, servaddr, std::move(GetSeed1));
	std::vector<XCPMsgPtr> UnlockMessages = master->CreateUnlockMessages();
	Send(s, servaddr, std::move(UnlockMessages[0]));

	// ################################### UPLOAD ###########################################
	std::cout << "Send XCP SET_MTA + UPLOAD.\n";
	SetMTA = master->CreateSetMTAMessage(0x12345678, 0);
	Send(s, servaddr, std::move(SetMTA));
	Upload = master->CreateUploadMessage(2);
	Send(s, servaddr, std::move(Upload));
	std::cout << "\n";

	// ################################### DOWNLOAD #########################################
	std::cout << "Send XCP SET_MTA + DOWNLOAD.\n";
	SetMTA = master->CreateSetMTAMessage(0x12345678, 0);
	Send(s, servaddr, std::move(SetMTA));
	Download = master->CreateDownloadMessage(data);
	Send(s, servaddr, std::move(Download));
	std::cout << "\n";

	std::cout << "Send XCP SHORT_DOWNLOAD.\n";
	ShortDownload = master->CreateShortDownloadMessage(0x12345678, 0, data);
	Send(s, servaddr, std::move(ShortDownload));
	std::cout << "\n";

	// ################################### DISCONNECT #######################################
	std::cout << "Send XCP DISCONNECT.\n";
	disconnect_message = master->CreateDisconnectMessage();
	Send(s, servaddr, std::move(disconnect_message));
	std::cout << "\n";

	close(s);
	return 0;
}

int LoadSO()
{
	void *hGetProcIDSO;

	// load the shared object
	hGetProcIDSO = dlopen(SEEDNKEYXCP_SO, RTLD_LAZY);
	if (!hGetProcIDSO) {
		std::cout << "could not load the dynamic library" << std::endl;
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	// clear any existing error
	dlerror();

	// check for XCP_GetAvailablePrivileges()
	GetAvailablePrivileges = (XCP_GetAvailablePrivilegesPtr_t)dlsym(hGetProcIDSO, "XCP_GetAvailablePrivileges");
	if (!GetAvailablePrivileges) {
		std::cout << "could not locate the function" << std::endl;
                exit(EXIT_FAILURE);
	}

	// check for XCP_ComputeKeyFromSeed()
	ComputeKeyFromSeed = (XCP_ComputeKeyFromSeedPtr_t)dlsym(hGetProcIDSO, "XCP_ComputeKeyFromSeed");
	if (!GetAvailablePrivileges) {
		std::cout << "could not locate the function" << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}

void Send(int s, struct sockaddr_in servaddr, XCPMsgPtr message)
{
	unsigned int len;

	// send data
	message->Serialize(bytes);
	sendto(s, (const char *)bytes.data(), bytes.size(), MSG_CONFIRM,
					(const struct sockaddr *) &servaddr, sizeof(servaddr));
	bytes.clear();

	// receive data
	bytes.resize(MaxRecvsize);
	master->AddSentMessage(message.get());
	int recv_size = recvfrom(s, (char*)&bytes[0], MaxRecvsize, MSG_WAITALL,
							(struct sockaddr *) &servaddr, &len);
	bytes.resize(recv_size);

	// print data
	for (int i = 0; i < recv_size; i++) {
		std::cout << std::hex << (int)(bytes[i] & 0xff) << " ";
	}
	std::cout << "\n";
	XCPMsgPtr asd = master->DeserializeMessage(bytes);
}
