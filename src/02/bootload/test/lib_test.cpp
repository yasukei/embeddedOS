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
		;
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

class memsetTest : public ::testing::TestWithParam< ::std::tr1::tuple<void*, void*, int, long> >
{
};

TEST_P(memsetTest, test1)
{
	void* ret	= ::std::tr1::get<0>(GetParam());
	void* buf	= ::std::tr1::get<1>(GetParam());
	int c		= ::std::tr1::get<2>(GetParam());
	long len	= ::std::tr1::get<3>(GetParam());

	EXPECT_TRUE(ret == memset(buf, c, len));
}

::std::tr1::tuple<void*, void*, int, long> memsetTest_testData[] = {
						// ret, buf, c, len
	std::tr1::make_tuple((void*)NULL, (void*)NULL, 0, 0),
};

INSTANTIATE_TEST_CASE_P(
	abc,
	memsetTest,
	::testing::ValuesIn(memsetTest_testData)
	);

