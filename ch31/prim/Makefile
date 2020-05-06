CXX=g++
CXXFLAGS=-g -Wall
OBJS=main.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): disjointset.h main.cpp
	$(CXX) $(CXXFLAGS) -c $^
