#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "ProduceManager.h"
#include "TestProgressPanel.h"
#include "TestSerialPortCommunicator.h"

using::testing::_;

TEST(ProduceManager, constructor) {
  TestProgressPanel panel;
  TestSerialPortCommunicator communicator;
  std::string code = "Y 10\nY 20\n";

  ProduceManager manager(code, &panel, &communicator);

  ASSERT_EQ(1, 1);
}

TEST(ProduceManager, thread) {
  TestProgressPanel panel;
  TestSerialPortCommunicator communicator;

  EXPECT_CALL(communicator, send(_)).Times(2);
  EXPECT_CALL(communicator, readline())
          .Times(2)
          .WillRepeatedly(testing::Return("ok"));

  EXPECT_CALL(panel, update(_)).Times(2);
  EXPECT_CALL(panel, reportCommand(_)).Times(2);
  EXPECT_CALL(panel, reportCheck()).Times(2);

  std::string code = "Y 10\nY 20\n";
  ProduceManager manager(code, &panel, &communicator);

  std::thread *thread = manager.startProduce();

  thread->join();
}

TEST(ProduceManager, thread_with_working) {
  TestProgressPanel panel;
  TestSerialPortCommunicator communicator;

  EXPECT_CALL(communicator, send(_)).Times(2);
  EXPECT_CALL(communicator, readline())
          .Times(4)
          .WillOnce(testing::Return(""))
          .WillOnce(testing::Return(""))
          .WillRepeatedly(testing::Return("ok"));

  EXPECT_CALL(panel, update(_)).Times(2);
  EXPECT_CALL(panel, reportCommand(_)).Times(2);
  EXPECT_CALL(panel, reportCheck()).Times(2);

  std::string code = "Y 10\nY 20\n";
  ProduceManager manager(code, &panel, &communicator);

  std::thread *thread = manager.startProduce();

  thread->join();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
