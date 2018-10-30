OPT = -std=c++11 -Wall -O3
HEADER = $(wildcard src/*.h)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = bin/main
OUTPUT = statistics/data_origin.txt

.PHONY: all
all: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$< > $(OUTPUT)

$(TARGET): $(OBJ) main.cpp
	g++ $(OPT) $^ -o $@ 

obj/%.o: src/%.cpp src/%.h
	g++ -c $(OPT) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET)
