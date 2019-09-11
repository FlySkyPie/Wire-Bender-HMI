#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <wx/bitmap.h>
#include <string>
#include "BlueprintButton.h"
#include "TestBlueprintDisplay.h"

TEST(BlueprintButton, constructor) {
  TestBlueprintDisplay display;
  wxBitmap bitmap;
  BlueprintButton button(NULL, wxID_ANY, bitmap, "name", &display);
  ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
