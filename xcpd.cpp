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
	XCPMsgPtr connect_message = master->CreateConnectMessage(ConnectPacket::ConnectMode::NORMAL);

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

	printf("Send XCP CONNECT.\n");
	Send(s, servaddr, std::move(connect_message));

	// TODO: implement SeedGet to calc key via external library and unlock SLAVE


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
