#pragma once

#include <XCPMaster.h>


XCPMaster* master;
std::vector<uint8_t> bytes;
int MaxRecvsize = 0xff;

void Send(int s, struct sockaddr_in servaddr, XCPMsgPtr message);
