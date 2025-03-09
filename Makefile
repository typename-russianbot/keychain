#TODO: | -MAKEFILE PASSWORD KEYCHAIN- |

#?? | -C++ Flags- |
CXX = g++
CXX_FLAGS = -g -Wall -std=c++11

#?? | -Source, Build, Target Files- |
BUILD = build 
SOURCES = source/main.cpp
OBJECTS = $(patsubst source/%.cpp, build/%.o, $(SOURCES))
TARGET = keychain

#&& | -Makefile Operations- |
all:  $(TARGET)

clean: 
	rm -rf $(TARGET) $(BUILD)
	clear

run: $(TARGET)
	./keychain

#^^ | -Compiling & Linking- |
# link all files together
$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(TARGET)

# Compile source files into object files
build/%.o: source/%.cpp 
	mkdir -p $(BUILD)  # Move directory creation here
	$(CXX) $(CXX_FLAGS) -c $< -o $@
