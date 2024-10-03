# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = queue

# Object files
OBJ = main.o queue.o

# Default target: compile and link
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile main.cpp into object file
main.o: main.cpp queue.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile queue.cpp into object file
queue.o: queue.cpp queue.h
	$(CXX) $(CXXFLAGS) -c queue.cpp

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)
