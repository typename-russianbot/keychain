#TODO: | -MAKEFILE PASSWORD KEYCHAIN- |

#?? | -C++ Flags- | 
CXX = g++
CXX_FLAGS = -g -Wall -std=c++11

BUILD = build 
SOURCES = source/main.cpp source/source.cpp
OBJECTS = $(patsubst source/%.cpp, build/%.o, $(SOURCES))
TARGET = keychain

#&& | -Makefile Operations- |

#&& all - 
all:  $(TARGET)

#&& clean - 
clean: 
	rm -rf $(TARGET) $(BUILD)
	clear

#&& run -
run: $(TARGET)
	./keychain

#^^ | -Compiling & Linking- |

#^^ 
$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(TARGET)

#^^ Compile source files into object files
build/%.o: source/%.cpp 
	mkdir -p $(BUILD)  # Move directory creation here
	$(CXX) $(CXX_FLAGS) -c $< -o $@
