#include <gtest/gtest.h>
#include <string>
#include "ProduceQueue.h"

TEST(ProduceQueue, getCommand) {
  std::string code;
  code = "Y 0\nY 2\n";

  ProduceQueue produceQueue(code);
  ASSERT_EQ("Y 0", produceQueue.getCommand());
  ASSERT_EQ("Y 2", produceQueue.getCommand());
}

TEST(ProduceQueue, isFinished) {
  std::string code;
  code = "Y 0\nY 2\n";

  ProduceQueue produceQueue(code);
  produceQueue.getCommand();
  produceQueue.getCommand();
  ASSERT_EQ(true, produceQueue.isFinished());
}

TEST(ProduceQueue, getProgress_1) {
  std::string code;
  code = "Y 0\nY 2\n";

  ProduceQueue produceQueue(code);
  produceQueue.getCommand();
  produceQueue.getCommand();
  ASSERT_EQ(1, produceQueue.getProgress());
}

TEST(ProduceQueue, getProgress_0) {
  std::string code;
  code = "Y 0\nY 2\n";

  ProduceQueue produceQueue(code);
  ASSERT_EQ(0, produceQueue.getProgress());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
