TEST_TARGET = bootload_test
SRC_DIR = ../

SRC_OBJS = \
	#$(SRC_DIR)/lib.o 

TEST_OBJS = \
	lib_test.o

INCLUDE_DIRS = \
   $(SRC_DIR)


CPPFLAGS += -I$(GTEST_DIR)/include -I$(GMOCK_DIR)/include -I$(INCLUDE_DIRS)
CXXFLAGS += -g -Wall -Wextra -std=c++0x

# targets.

all : test

clean :
	rm -f gmock.a gmock_main.a *.o
	rm -rf $(TEST_TARGET) $(SRC_OBJS) $(TEST_OBJS)

only : $(TEST_TARGET)

test : $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET) : gmock_main.a $(TEST_OBJS) $(SRC_OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -pthread -o $@

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

include gtestgmock.mk

