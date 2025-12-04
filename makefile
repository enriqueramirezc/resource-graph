# Compilador y Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include -no-pie
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -no-pie
TESTFLAGS = -lgtest -lgtest_main -pthread -no-pie
CPPLINT_FLAGS = --filter=-build/include_subdir,-readability/casting,-runtime/references

# Directorios
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Archivos fuente
CPP_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Archivos objeto
CPP_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SOURCES))

OBJECTS = $(CPP_OBJECTS) $(ASM_OBJECTS)

# Ejecutables
TARGET = $(BIN_DIR)/program

# Target principal
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compilar C++
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar tests
$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Correr programa
run: $(TARGET)
	./$(TARGET)

# Clean todo
clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/program $(BIN_DIR)/test_runner

# Pasarle cpplint a los archivos cpp
lint-src:
	cpplint $(CPPLINT_FLAGS) $(SRC_DIR)/*.cpp

# Pasarle cpplint a los archivos h
lint-include:
	cpplint $(CPPLINT_FLAGS) $(INCLUDE_DIR)/*.hpp

.PHONY: all clean run lint-include lint-src
