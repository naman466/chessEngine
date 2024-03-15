# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra
# Source files
SRCS := board.cpp engine.cpp init.cpp 
# Object files
OBJS := $(SRCS:.cpp=.o)
# Executable name
EXEC := chess_engine

# Default target
all: $(EXEC)

# Linking rule
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(EXEC) $(OBJS)
