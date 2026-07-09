CXX = g++
CXXFLAGS = -Wall -g -Iinclude -MMD -MP

TARGET = App
BUILD_DIR = build

SRCS = $(wildcard src/*.cpp)

OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

DEPS = $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) *.d