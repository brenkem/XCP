#pragma once
#include "CommandPacket.h"
#include "ResponsePacket.h"


// Download from master to slave
class DownloadPacket final :
	public CommandPacket
{
public:
	// Number of dataelements: 1..[MAXCTO/AG - 1] in standardmode, 1..255 in block mode
	DownloadPacket(const std::vector<uint8_t>& Data);
	virtual ~DownloadPacket();
	void SetNumberOfDataElements(uint8_t num);
	uint8_t GetNumberOfDataElements();
};

//------------------------------------------------------------------------------------------------------------------------------------------------------

class DownloadResponse final : public ResponsePacket
{
private:
	uint8_t m_AG;
	uint8_t m_ElementSizeInBytes;
	uint8_t m_NumberOfElements;
	DownloadResponse(const std::vector<uint8_t>& Data, uint8_t HeaderSize, uint8_t AG);
public:
	~DownloadResponse();
	static DownloadResponse* Deserialize(const std::vector<uint8_t>& Data, uint8_t HeaderSize, uint8_t AG);
	uint8_t GetNumberOfElements();
	template<typename T>
	T GetElement(uint8_t id, bool LittleEndian) = delete;

	virtual void Dispatch(IIncomingMessageHandler& Handler);
};

template<> inline uint8_t DownloadResponse::GetElement<uint8_t>(uint8_t id, bool LittleEndian)
{
	(void)LittleEndian; // Added this line to remove WARNING [Unused Parameter]
	return m_Data[id];
};

template<> inline uint16_t DownloadResponse::GetElement<uint16_t>(uint8_t id, bool LittleEndian)
{
	uint16_t t1, t2;
	t1 = m_Data[1 + id * 2];
	t2 = m_Data[1 + id * 2 + 1];

	if (LittleEndian)
	{
		return ((t2) << 8) | t1;
	}
	else
	{
		// do byte-swap
		return ((t1) << 8) | t2;
	}
};

template<> inline uint32_t DownloadResponse::GetElement<uint32_t>(uint8_t id, bool LittleEndian)
{
	if (LittleEndian)
	{
		return  (((uint32_t)m_Data[3 + id * 4 + 3]) << 24) | (((uint32_t)m_Data[3 + id * 4 + 2]) << 16) | (((uint32_t)m_Data[3 + id * 4 + 1]) << 8) | m_Data[3 + id * 4];
	}
	else
	{
		// do byte-swap
		return (((uint32_t)m_Data[3 + id * 4]) << 24) | (((uint32_t)m_Data[3 + id * 4 + 1]) << 16) | (((uint32_t)m_Data[3 + id * 4 + 2]) << 8) | m_Data[3 + id * 4 + 3];
	}
};

//-------------------------------------------------------------------------------------------------------------------------

class ShortDownloadPacket final : public CommandPacket
{
	enum BytePositions
	{
		NUMBER_OF_DATA_ELEMENTS = 0,
		RESERVED = 1,
		ADDRESS_EXTENSION = 2,
		ADDRESS = 3,
		DATA = 7
	};
public:
	ShortDownloadPacket(const std::vector<uint8_t>& Data);
	virtual ~ShortDownloadPacket();
	void SetAddress(uint32_t Address, bool LittleEndian);
	uint32_t GetAddress(bool LittleEndian);
	uint8_t GetAddressExtension();
	void SetAddressExtension(uint8_t AddressExtension);
	void SetNumberOfDataElements(uint8_t NumberOfDataElements);
	uint8_t GetNumberOfDataElements();
};
