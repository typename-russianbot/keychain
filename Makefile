CXX = g++
CXX_FLAGS = -g -Wall -std=c++11 

TARGET = keychain
BUILD = build 

SOURCES = src/main.cpp
OBJECTS = $(patsubst srcs/%.cpp, $(BUILD)/%.o, $(SOURCES))

all: $(TARGET)

clean: 
	rm -rf $(TARGET) $(BUILD)
	clear

run: 
	./keychain

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(TARGET)

build/%.o: src/%.cpp | $(BUILD)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BUILD): 
	mkdir -p $(BUILD)