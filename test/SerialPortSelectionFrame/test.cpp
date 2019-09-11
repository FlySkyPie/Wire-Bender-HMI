#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SerialPortSelectionFrame.h"
#include "TestSerialPortList.h"
#include "TestSerialPortConfigurer.h"

using::testing::_;

/*
 * This is not unit test really,
 * just for testing syntax error.
 */

TEST(SerialPortSelectionFrame, constructor) {
  TestSerialPortList portList;
  TestSerialPortConfigurer configurer;

  EXPECT_CALL(portList, getPorts()).Times(1);

  SerialPortSelectionFrame(&configurer, &portList);

  ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
