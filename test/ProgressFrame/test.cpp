#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ProgressFrame.h"
#include "TestProduceManagerFactory.h"
#include "TestStopProduce.h"

using::testing::_;

/*
 * This is not unit test really,
 * just for testing syntax error.
 */

TEST(ProgressFrame, constructor) {
  TestProduceManagerFactory factory;
  TestStopProduce stopHandler;

  ProgressFrame frame(&factory, &stopHandler);

  SUCCEED();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}