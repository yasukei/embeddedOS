#include "defines.h"
#include "serial.h"

class MockSerial
{
	public:
		MOCK_METHOD1(serial_init, int(int index));
		MOCK_METHOD2(serial_send_byte, int(int index, unsigned char c));
		MOCK_METHOD1(serial_is_send_enable, int(int index));
};

MockSerial* gMockSerial;

void MockSerial_set(MockSerial* mockSerial)
{
	gMockSerial = mockSerial;
}

int serial_init(int index)
{
	return gMockSerial->serial_init(index);
}

int serial_send_byte(int index, unsigned char c)
{
	return gMockSerial->serial_send_byte(index, c);
}

int serial_is_send_enable(int index)
{
	return gMockSerial->serial_is_send_enable(index);
}
