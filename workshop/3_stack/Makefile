# Makefile for Stack example
CC=g++
CFLAGS=-Wall -std=c++20
SRC=Main.cpp
TARGET=main

all: $(TARGET)

$(TARGET): $(SRC) Stack.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
