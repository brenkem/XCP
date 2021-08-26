#pragma once

#include <XCPMaster.h>


XCPMaster* master;
std::vector<uint8_t> bytes;
int MaxRecvsize = 0xff;

XCP_GetAvailablePrivilegesPtr_t GetAvailablePrivileges = NULL;
XCP_ComputeKeyFromSeedPtr_t ComputeKeyFromSeed = NULL;

int LoadSO();
void Send(int s, struct sockaddr_in servaddr, XCPMsgPtr message);
