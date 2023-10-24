#include "DownloadPacket.h"



DownloadPacket::DownloadPacket(const std::vector<uint8_t>& Data) : CommandPacket()
{
	m_PID = CTOMasterToSlaveCommands::DOWNLOAD;
	m_DataLength = (uint32_t)Data.size() + 1;
	m_PacketSize = m_DataLength + 1;
	m_Data = new uint8_t[m_DataLength + 1];
        m_Data[0] = Data.size(); // NumberOfDataElements;
	for (unsigned int i = 0; i < m_Data[0]; i++)
	{
		m_Data[i + 1] = Data[i];
	}
}


DownloadPacket::~DownloadPacket()
{
	delete[] m_Data;
	m_Data = nullptr;
}

void DownloadPacket::SetNumberOfDataElements(uint8_t num)
{
	m_Data[0] = num;
}

uint8_t DownloadPacket::GetNumberOfDataElements()
{
	return m_Data[0];
}

//----------------------------------------------------------------------------------------------------

DownloadResponse::DownloadResponse(const std::vector<uint8_t>& Data, uint8_t HeaderSize, uint8_t AG) : ResponsePacket()
{
	m_DataLength = (uint32_t)Data.size() - HeaderSize - 1; // size -headersize - PID fieldsize
	m_PacketSize = m_DataLength + 1;
	m_Data = new uint8_t[m_DataLength];
	for (unsigned int i = 0; i < m_DataLength; i++)
	{
		m_Data[i] = Data[HeaderSize + 1 + i];
	}
	m_AG = AG;
	m_ElementSizeInBytes = 1 << AG;
	if (m_ElementSizeInBytes == 1)
	{
		m_NumberOfElements = m_DataLength;
	}
	else if (m_ElementSizeInBytes == 2)
	{
		m_NumberOfElements = (m_DataLength - 1)/2;
	}
	else if (m_ElementSizeInBytes == 4)
	{
		m_NumberOfElements = (m_DataLength - 3)/4;
	}
	else // ERROR
	{
		m_NumberOfElements = 0;
	}
}

DownloadResponse::~DownloadResponse()
{
	delete[] m_Data;
	m_Data = nullptr;
}

DownloadResponse * DownloadResponse::Deserialize(const std::vector<uint8_t>& Data, uint8_t HeaderSize, uint8_t AG)
{
	return new DownloadResponse(Data, HeaderSize, AG);
}

uint8_t DownloadResponse::GetNumberOfElements()
{
	return m_NumberOfElements;
}

void DownloadResponse::Dispatch(IIncomingMessageHandler & Handler)
{
	Handler.Handle(*this);
}

//------------------------------------------------------------------------------------------------------------------

ShortDownloadPacket::ShortDownloadPacket(const std::vector<uint8_t>& Data) : CommandPacket()
{
	m_PID = CTOMasterToSlaveCommands::SHORT_DOWNLOAD;
	m_DataLength = (uint32_t)Data.size() + 7;
	m_PacketSize = m_DataLength + 1;
	m_Data = new uint8_t[m_DataLength + 6];
        m_Data[0] = Data.size(); // NumberOfDataElements;
	m_Data[BytePositions::RESERVED] = 0;

	for (unsigned int i = 0; i < m_Data[0]; i++)
	{
		m_Data[i + 7] = Data[i];
	}


}

ShortDownloadPacket::~ShortDownloadPacket()
{
	delete[] m_Data;
	m_Data = nullptr;
}

uint32_t ShortDownloadPacket::GetAddress(bool LittleEndian)
{
	if (LittleEndian)
	{
		return  (((uint32_t)m_Data[BytePositions::ADDRESS + 3]) << 24) | (((uint32_t)m_Data[BytePositions::ADDRESS + 2]) << 16) | (((uint32_t)m_Data[BytePositions::ADDRESS + 1]) << 8) | m_Data[BytePositions::ADDRESS];
	}
	else
	{
		// do byte-swap
		return (((uint32_t)m_Data[BytePositions::ADDRESS]) << 24) | (((uint32_t)m_Data[BytePositions::ADDRESS + 1]) << 16) | (((uint32_t)m_Data[BytePositions::ADDRESS + 2]) << 8) | m_Data[BytePositions::ADDRESS + 3];
	}
}

void ShortDownloadPacket::SetAddress(uint32_t Address, bool LittleEndian)
{
	uint8_t i1, i2, i3, i4;
	i1 = Address & 0xFF;
	i2 = (Address >> 8) & 0xFF;
	i3 = (Address >> 16) & 0xFF;
	i4 = (Address >> 24) & 0xFF;

	if (LittleEndian)
	{
		m_Data[BytePositions::ADDRESS] = i1;
		m_Data[BytePositions::ADDRESS + 1] = i2;
		m_Data[BytePositions::ADDRESS + 2] = i3;
		m_Data[BytePositions::ADDRESS + 3] = i4;
	}
	else
	{
		m_Data[BytePositions::ADDRESS] = i4;
		m_Data[BytePositions::ADDRESS + 1] = i3;
		m_Data[BytePositions::ADDRESS + 2] = i2;
		m_Data[BytePositions::ADDRESS + 3] = i1;
	}
}

uint8_t ShortDownloadPacket::GetAddressExtension()
{
	return m_Data[BytePositions::ADDRESS_EXTENSION];
}

void ShortDownloadPacket::SetAddressExtension(uint8_t AddressExtension)
{
	m_Data[BytePositions::ADDRESS_EXTENSION] = AddressExtension;
}

void ShortDownloadPacket::SetNumberOfDataElements(uint8_t NumberOfDataElements)
{
	m_Data[BytePositions::NUMBER_OF_DATA_ELEMENTS] = NumberOfDataElements;
}

uint8_t ShortDownloadPacket::GetNumberOfDataElements()
{
	return m_Data[BytePositions::NUMBER_OF_DATA_ELEMENTS];
}
