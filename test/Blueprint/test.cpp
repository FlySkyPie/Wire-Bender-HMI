#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Blueprint.h"
#include "TestBlueprintStorage.h"

using::testing::_;

TEST(Blueprint, getInfo) {
  TestBlueprintStorage storage;

  EXPECT_CALL(storage, getInfo(_)).WillOnce(testing::Return("XD"));

  Blueprint blueprint(&storage, "");
  ASSERT_EQ("XD", blueprint.getInfo());
}

TEST(Blueprint, getCode) {
  TestBlueprintStorage storage;

  EXPECT_CALL(storage, getCode(_)).WillOnce(testing::Return("XD"));

  Blueprint blueprint(&storage, "");
  ASSERT_EQ("XD", blueprint.getCode());
}

TEST(Blueprint, getPreview) {
  TestBlueprintStorage storage;

  EXPECT_CALL(storage, getPreview(_)).Times(1);

  Blueprint blueprint(&storage, "");
  blueprint.getPreview();
}

TEST(Blueprint, getShape) {
  TestBlueprintStorage storage;

  EXPECT_CALL(storage, getShape(_)).Times(1);

  Blueprint blueprint(&storage, "");
  blueprint.getShape();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
