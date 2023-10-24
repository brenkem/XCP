#pragma once
#include "ErrorPacket.h"
class ErrorAccessDeniedPacket final :
	public ErrorPacket
{
private:
	enum BytePositions
	{
		ErrorCode = 0x0,
	};
public:
	ErrorAccessDeniedPacket();
	virtual ~ErrorAccessDeniedPacket();
	virtual void Dispatch(IIncomingMessageHandler& Handler);
};
