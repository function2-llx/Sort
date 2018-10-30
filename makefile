OPT = -std=c++11 -Wall
HEADER = $(wildcard src/*.h)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = bin/main

.PHONY: all
all: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$<

$(TARGET): $(OBJ) main.cpp
	g++ $(OPT) $^ -o $@

obj/%.o: src/%.cpp src/%.h
	g++ -c $(OBT) $< -o $@

