# Define the C++ compiler to use
CXX = g++

# Define compiler flags (e.g., -Wall for all warnings, -g for debugging info)
CXXFLAGS = -Wall -g

# Define the name of the executable
TARGET = main

# Define the source file
SRC = main.cpp

# Define the object file (generated from the source file)
OBJ = $(SRC:.cpp=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link the object file(s) into the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile the source file into an object file
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target for cleaning up build artifacts
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
