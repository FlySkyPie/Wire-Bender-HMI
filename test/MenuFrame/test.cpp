#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TestStartProduce.h"
#include "MenuFrame.h"

TEST(MenuFrame, constructor) {
  TestStartProduce startHandler;
  
  MenuFrame frame(&startHandler);

  SUCCEED();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
