#include "xcpd.h"


int main(int argc, char *argv[])
{

	XCPMaster* master = new XCPMaster(TransportLayer::ETHERNET);
/*	master->SetSeedAndKeyFunctionPointers(
		GetAvailablePrivileges, //function pointer for the GetAvailablePrivileges
		ComputeKeyFromSeed); //function pointer for the ComputeKeyFromSeed
	IncomingHandlerExternal* Handler = new IncomingHandlerExternal(thread, master); //It is my implementation of the IIncomingMessageHandler interface. Your implementation can be different.
	master->SetExternalMessageHandler(Handler);
*/

	return 0;
}
