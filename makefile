CC=g++
#CCFLAGS=-std=c++0x -c
#INCLUDE_DIRS=include
#SOURCES=
#OBJECTS=$(SOURCES:.cpp=.o)
#LIBRARY=bin/libcputil.a

TEST_INCLUDE_DIRS=-Iinclude -Itpunitpp
TEST_SOURCES=tests/cpfile_test.cpp tests/cputil_main.cpp
TEST_RUNNER_APP=test_runner
TEST_RUNNER_PATH=tests/$(TEST_RUNNER_APP)

#all: $(SOURCES) $(LIBRARY)
all: test

#$(LIBRARY) : $(OBJECTS)
#	ar rvs $(LIBRARY) $(OBJECTS)

#.cpp.o:
#	$(CC) $(CCFLAGS) $< -I $(INCLUDE_DIRS) -o $@

test: 
	$(CC) $(TEST_SOURCES) $(TEST_INCLUDE_DIRS) -o $(TEST_RUNNER_PATH)

clean:
	rm -rf *.o *.a
	rm $(TEST_RUNNER_PATH)
