CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
OBJS=main.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): main.cpp
	$(CXX) $(CXXFLAGS) -c $^
