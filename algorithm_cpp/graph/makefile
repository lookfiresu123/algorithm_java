CXX = clang++
CXXFLAGS=-g -std=c++11 -Wall -fstandalone-debug -pedantic
SOURCE = test.cpp
OBJECT = test.o
OBJECTALL = $(OBJECT) BaseGraph.o DepthFirstPaths.o BreadthFirstPaths.o
EXEC = test

all:
	cd BaseGraph; make; mv BaseGraph.o ../
	cd DepthFirstPaths; make; mv DepthFirstPaths.o ../
	cd BreadthFirstPaths; make; mv BreadthFirstPaths.o ../
	$(CXX) -c $(SOURCE) $(CXXFLAGS) -o $(OBJECT)
	$(CXX) $(OBJECTALL) $(CXXFLAGS) -o $(EXEC)

clean:
	rm -f $(EXEC) *.gdb *.o
