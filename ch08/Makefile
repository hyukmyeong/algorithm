CXX=g++
CXXFLAGS=-g -std=c++17 -Wall
OBJS=main.o
TARGET=a.out

.PHONY: $(OBJS) $(TARGET)
.SILENT: $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	echo -e
	./a.out

$(OBJS): main.cpp
	$(CXX) $(CXXFLAGS) -c $^
