#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <wx/bitmap.h>
#include <string>

#include "BlueprintDisplayPanel.h"
#include "TestBlueprintStorage.h"
#include "TestStartProduce.h"

using::testing::_;

/*
 * This is not unit test really,
 * just for testing syntax error.
 */

TEST(BlueprintDisplayPanel, constructor) {
  TestBlueprintStorage testStorage;
  TestStartProduce productController;

  EXPECT_CALL(testStorage, getBlueprint(_)).Times(1);

  BlueprintDisplayPanel(NULL, wxID_ANY, &testStorage, &productController);

  ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
