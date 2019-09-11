#!/bin/bash
SOURCE_PATH="./../../src/"
INCLUE_PATH="./../../include/"

# compile the test code
g++ test.cpp \
${SOURCE_PATH}BlueprintListPanel.cpp \
${SOURCE_PATH}BlueprintButton.cpp \
`wx-config --cxxflags --libs std` -lgtest -lpthread -lgmock -std=c++17 -lstdc++fs -Wall \
-I ${INCLUE_PATH} -I ${SOURCE_PATH}. \
-o test.o

# execute the test and remove executable.
./test.o --gtest_color=yes
rm test.o

