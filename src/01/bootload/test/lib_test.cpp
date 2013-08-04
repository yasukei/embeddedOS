#include "gtest/gtest.h"
#include "gmock/gmock.h"
using ::testing::_;

// include headers for testing in non-target environment
#include "defines_test.h"
#include "lib_test.h"

// include product code
extern "C"
{
#include "../lib.h"
#include "../lib.c"
}

// include mock
#include "mock-serial.cpp"

class lib_test : public ::testing::Test
{
	public:
		MockSerial mockSerial;

	virtual void SetUp()
	{
		MockSerial_set(&mockSerial);
	}

	virtual void TearDown()
	{
		MockSerial_set((MockSerial*)NULL);
		;
	}
};

TEST_F(lib_test, test1)
{
	//EXPECT_CALL(mockSerial, serial_send_byte(_, 'a'));

	putc('a');
}

//TEST_F(lib_test, test2)
//{
//	EXPECT_CALL(mockSerial, serial_send_byte(_, 'b'));
//
//	putc('b');
//}

