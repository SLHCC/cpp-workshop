# Makefile for building Main.cpp and ArrayWrapper.cpp
CC=g++
CFLAGS=-Wall -std=c++20
SRC=Main.cpp ArrayWrapper.cpp
OBJ=$(SRC:.cpp=.o)
TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp ArrayWrapper.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
