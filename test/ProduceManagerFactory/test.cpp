#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ProduceManagerFactory.h"
#include "TestProgressPanel.h"
#include "TestSerialPortCommunicator.h"

using::testing::_;

/*
 * Test it can be constructed.
 */
TEST(ProduceManagerFactory, constructor) {
  TestProgressPanel testProgressPanel;
  TestSerialPortCommunicator communicator;
  ProduceManagerFactory factory(&testProgressPanel, &communicator);

  SUCCEED();
}

/*
 * Test it can get IProduceManager.
 */
TEST(ProduceManagerFactory, getProduceManager) {
  TestProgressPanel testProgressPanel;
  TestSerialPortCommunicator communicator;
  ProduceManagerFactory factory(&testProgressPanel, &communicator);

  IProduceManager* manager = factory.getProduceManager("");

  SUCCEED();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
