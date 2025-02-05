
CXX := g++
CXXFLAGS := -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -fsanitize=address 

SRC_DIR := src
SRCS := $(SRC_DIR)/holder.cpp \
		$(SRC_DIR)/is_balanced.cpp \
        $(SRC_DIR)/main.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := hw4

GTEST_TARGET := run_tests
TEST_DIR := gtest
GTEST_SRCS := $(TEST_DIR)/student_gtests.cpp
GTEST_OBJS := $(GTEST_SRCS:.cpp=.o)
LDFLAGS := -lgtest -lgtest_main -pthread

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(GTEST_OBJS) $(SRC_DIR)/holder.o $(SRC_DIR)/is_balanced.o
	$(CXX) $(CXXFLAGS) -o $(GTEST_TARGET) $(GTEST_OBJS) $(SRC_DIR)/holder.o $(SRC_DIR)/is_balanced.o $(LDFLAGS)
	./$(GTEST_TARGET)

BALANCED_SRCS := $(SRC_DIR)/is_balanced.cpp $(SRC_DIR)/is_balanced_main.cpp
BALANCED_OBJS := $(BALANCED_SRCS:.cpp=.o)
BALANCED_TARGET := is_balanced

balanced: $(BALANCED_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BALANCED_TARGET) $(BALANCED_OBJS)
	./$(BALANCED_TARGET)

clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(TARGET) $(GTEST_TARGET) $(BALANCED_TARGET)
