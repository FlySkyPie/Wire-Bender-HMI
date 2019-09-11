#!/bin/bash
SOURCE_PATH="./../../src/"

# compile the test code
g++ test.cpp \
${SOURCE_PATH}ProduceQueue.cpp \
-lgtest -std=c++17 -lstdc++fs -Wall \
-I ${SOURCE_PATH}interface -I ${SOURCE_PATH}. \
-o test.o

# execute the test and remove executable.
./test.o --gtest_color=yes
rm test.o