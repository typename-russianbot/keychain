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

#&& 1. all - create all object & executable files
all:  $(TARGET) 
	clear

#&& 2. clean - remove object files & executables
clean: 
	rm -rf $(TARGET) $(BUILD) && clear

#&& 3. run - start program
run: $(TARGET) 
	./keychain

#&& 4. test - start program w/ test flags
test: $(TARGET) 
	./keychain -v
	
#&& | --------------------- |

#^^ | -Compiling & Linking- |

$(TARGET): $(OBJECTS) #^^ 1. link all files
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(TARGET)

build/%.o: source/%.cpp #^^ 2. compile source code
	mkdir -p $(BUILD)  # Move directory creation here
	$(CXX) $(CXX_FLAGS) -c $< -o $@

#^^ | --------------------- |
