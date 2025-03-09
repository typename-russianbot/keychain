#TODO: | -MAKEFILE PASSWORD KEYCHAIN- |

#?? | -C++ Flags- | 

CXX = g++ #?? 1. gdb compiler
CXX_FLAGS = -g -Wall -std=c++11 #?? C++ flags

BUILD = build #?? build directory
SOURCES = source/main.cpp source/key.cpp source/keynode.cpp source/keychain.cpp #?? source files
OBJECTS = $(patsubst source/%.cpp, build/%.o, $(SOURCES)) #?? objects files
TARGET = keychain #?? target executable

#?? | ----------- | 

#&& | -Makefile Operations- |

all:  $(TARGET) #&& 1. all - create all object & executable files
	clear

clean: #&& 2. clean - remove object files & executables
	rm -rf $(TARGET) $(BUILD)
	clear

run: $(TARGET) #&& 3. run - start program
	./keychain
	
#&& | --------------------- |

#^^ | -Compiling & Linking- |

$(TARGET): $(OBJECTS) #^^ 1. link all files
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(TARGET)

build/%.o: source/%.cpp #^^ 2. compile source code
	mkdir -p $(BUILD)  # Move directory creation here
	$(CXX) $(CXX_FLAGS) -c $< -o $@

#^^ | --------------------- |
