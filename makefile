OPT = -std=c++11 -Wall -O3
HEADER = $(wildcard src/*.h)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = bin/main
INPUT = parameter.txt

.PHONY: all
all: $(TARGET)

.PHONY: origin
origin: $(TARGET)
	./$< < parameter.txt

.PHONY: improved
improved: $(TARGET)
	./$< improved < parameter.txt`

$(TARGET): $(OBJ) main.cpp
	g++ $(OPT) $^ -o $@ 

obj/%.o: src/%.cpp src/%.h
	g++ -c $(OPT) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET)