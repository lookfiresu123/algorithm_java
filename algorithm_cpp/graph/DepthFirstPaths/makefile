CXX = clang++
CXXFLAGS=-g -std=c++11 -Wall -fstandalone-debug -pedantic
SOURCE = DepthFirstPaths.cpp
OBJECT = DepthFirstPaths.o

all:
	$(CXX) -c $(SOURCE) $(CXXFLAGS) -o $(OBJECT)

clean:
	rm -f $(OBJECT) *.gdb *.o
