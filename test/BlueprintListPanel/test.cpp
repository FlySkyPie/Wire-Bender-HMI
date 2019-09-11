#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <wx/bitmap.h>
#include <string>
#include "BlueprintListPanel.h"
#include "TestBlueprintDisplay.h"
#include "TestShapeDisplay.h"

/*
 * This is not unit test really,
 * just for testing syntax error.
 */

TEST(BlueprintListPanel, constructor) {
  TestBlueprintDisplay blueprintDisplay;
  TestShapeDisplay shapesDisplay;

  EXPECT_CALL(shapesDisplay, getShapes()).Times(1);

  BlueprintListPanel(NULL, wxID_ANY, &shapesDisplay, &blueprintDisplay);

  ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
