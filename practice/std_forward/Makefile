TARGET:=test
CFLAGS:=-std=c++11
SRCS:=$(wildcard *.cpp)
OBJS:=$(patsubst %c,%o,$(SRCS))

all: test

$(TARGET): $(OBJS)
	g++ -o $@ $(CFLAGS) ${OBJS}
