GCC = g++
FLAGS= -g -Wall -std=c++11

BUILD = build 

SOURCES = src/main.cpp
OBJECTS = $(patsubst srcs/%.cpp, $(BUILD)/%.o, $(SOURCES))
EXEC = keychain
all:  $(EXEC)

clean: 
	rm -rf $(EXEC) $(BUILD)
	clear

run: 
	./keychain

$(EXEC): $(OBJECTS)
	$(GCC) $(FLAGS) $(OBJECTS) -o $(EXEC)

main.o: main.cpp | build	
	@echo "creating object files"
	$(GCC) $(FLAGS) -c main.cpp -o main.o

$(BUILD): 
	mkdir -p $(BUILD)