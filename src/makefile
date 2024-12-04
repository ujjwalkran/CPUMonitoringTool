# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = .
BUILD_DIR = ../build
DATA_DIR = ../data
LOG_DIR = ../logs

# Target executable
TARGET = $(BUILD_DIR)/resource_monitor

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default rule
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR) $(DATA_DIR) $(LOG_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
