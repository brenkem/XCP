/*
	This routine is only a example to perform a XCP CONNECT
	to an connected SLAVE on a configured (IP settings) network.
	See QtGUI/XCPWorkerThread.{cpp,h} of forked repository.
*/

/*
	XCP example with the following parameter:

	Protocol:       UDP
	Port:           5555 (src & dst)
	IP:		160.48.199.33/24
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "xcpd.h"

#define PORT			5555


int main(int argc, char *argv[])
{
	int s;
	XCPMsgPtr message;
	struct sockaddr_in servaddr, srcaddr;
	master = new XCPMaster(TransportLayer::ETHERNET);

	// Creating socket file descriptor
	if ( (s = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Filling client information
	memset(&srcaddr, 0, sizeof(srcaddr));
	srcaddr.sin_family = AF_INET;
	srcaddr.sin_addr.s_addr= htonl(INADDR_ANY);
	srcaddr.sin_port = htons(PORT);
	bind(s, (struct sockaddr *) &srcaddr, sizeof(srcaddr));

	// Filling server information
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("160.48.199.33");

//LoadDLL();
/*
	master->SetSeedAndKeyFunctionPointers(
		GetAvailablePrivileges,		//function pointer for the GetAvailablePrivileges
		ComputeKeyFromSeed);		//function pointer for the ComputeKeyFromSeed
*/


	std::cout << "Send XCP CONNECT.\n";
	XCPMsgPtr connect_message = master->CreateConnectMessage(ConnectPacket::ConnectMode::NORMAL);
	Send(s, servaddr, std::move(connect_message));
	MaxRecvsize = master->GetSlaveProperties().MaxDto;
	std::cout << "\n";

	std::cout << "Send XCP GET_STATUS.\n";
	XCPMsgPtr GetStatus = master->CreateGetStatusMessage();
	Send(s, servaddr, std::move(GetStatus));
	std::cout << "\n";


	// TODO: implement SeedGet to calc key via external library and unlock SLAVE
/*	std::cout << "Send to get seed.\n";
	XCPMsgPtr GetSeed1 = master->CreateGetSeedMessage(GetSeedPacket::Mode::FIRST_PART, GetSeedPacket::Resource::DAQ);
	Send(s, servaddr, std::move(GetSeed1));
	std::vector<XCPMsgPtr> UnlockMessages = master->CreateUnlockMessages();
	Send(s, servaddr, std::move(UnlockMessages[0]));
*/

	std::cout << "Send XCP SET_MTA + UPLOAD.\n";
//	XCPMsgPtr SetMTA = master->CreateSetMTAMessage(0x4000524C, 0);
//	XCPMsgPtr SetMTA = master->CreateSetMTAMessage(0x4007661A, 0);
	XCPMsgPtr SetMTA = master->CreateSetMTAMessage(0x4000E1A8, 0);
	Send(s, servaddr, std::move(SetMTA));
	XCPMsgPtr Upload = master->CreateUploadMessage(2);
	Send(s, servaddr, std::move(Upload));
	std::cout << "\n";


	std::cout << "Send XCP SHORT_UPLOAD.\n";
//	XCPMsgPtr ShortUpload = master->CreateShortUploadMessage(5, 0x4000524C, 0);
//	XCPMsgPtr ShortUpload = master->CreateShortUploadMessage(1, 0x4007661A, 0);
	XCPMsgPtr ShortUpload = master->CreateShortUploadMessage(2, 0x4000E1A8, 0);
	Send(s, servaddr, std::move(ShortUpload));
	std::cout << "\n";


	std::cout << "Send XCP DISCONNECT.\n";
	XCPMsgPtr disconnect_message = master->CreateDisconnectMessage();
	Send(s, servaddr, std::move(disconnect_message));
	std::cout << "\n";

	close(s);
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
