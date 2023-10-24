#include "ErrorAccessDeniedPacket.h"



ErrorAccessDeniedPacket::ErrorAccessDeniedPacket() : ErrorPacket()
{
	m_Data = new uint8_t[1];
	m_Data[BytePositions::ErrorCode] = ErrorCodes::ERR_ACCESS_DENIED;
	m_DataLength = 1;
	m_PacketSize = 2;
}


ErrorAccessDeniedPacket::~ErrorAccessDeniedPacket()
{
	delete[] m_Data;
	m_Data = nullptr;
}

void ErrorAccessDeniedPacket::Dispatch(IIncomingMessageHandler & Handler)
{
	Handler.Handle(*this);
}
