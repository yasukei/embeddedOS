#include <tuple>
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
	}
};

TEST_F(lib_test, test1)
{
	EXPECT_CALL(mockSerial, serial_send_byte(_, 'a'));

	putc('a');
}

TEST_F(lib_test, test2)
{
	EXPECT_CALL(mockSerial, serial_send_byte(_, 'b'));

	putc('b');
}

class memsetTest : public ::testing::TestWithParam< ::std::tr1::tuple<void*, int, long> >
{
};

TEST_P(memsetTest, test1)
{
	void* buf	= ::std::tr1::get<0>(GetParam());
	int c		= ::std::tr1::get<1>(GetParam());
	long len	= ::std::tr1::get<2>(GetParam());
	void* ret;

	ret = memset(buf, c, len);

	// TODO: under construction
	EXPECT_EQ(buf, ret);
	//for(int i = 0; i < len; i++)
	//{
	//	EXP
	//}
}

int gArrayForMemsetTest[32];

::std::tr1::tuple<void*, int, long> memsetTest_testData[] = {
						//	buf,			c,	len
	std::tr1::make_tuple(	(void*)NULL,	0,	0),
};

INSTANTIATE_TEST_CASE_P(
	abc,
	memsetTest,
	::testing::ValuesIn(memsetTest_testData)
	);

