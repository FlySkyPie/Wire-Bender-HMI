#include <gtest/gtest.h>
#include <wx/bitmap.h>
#include "BlueprintStorage.h"

TEST(BlueprintStorage, getInfo) {
  BlueprintStorage storage;
  ASSERT_EQ("XD\n", storage.getInfo("test_0"));
}

TEST(BlueprintStorage, getCode) {
  BlueprintStorage storage;
  ASSERT_EQ("Y 20\n", storage.getCode("test_0"));
}

TEST(BlueprintStorage, getPreview) {
  BlueprintStorage storage;
  wxBitmap image = storage.getPreview("test_0");
  ASSERT_EQ(400, image.GetSize().GetWidth());
  ASSERT_EQ(300, image.GetSize().GetHeight());
}

TEST(BlueprintStorage, getShape) {
  BlueprintStorage storage;
  wxBitmap image = storage.getShape("test_0");
  ASSERT_EQ(128, image.GetSize().GetWidth());
  ASSERT_EQ(128, image.GetSize().GetHeight());
}

TEST(BlueprintStorage, getShapes) {
  std::map<std::string, wxBitmap> shapes;
  BlueprintStorage storage;
  shapes = storage.getShapes();
  
  ASSERT_EQ(1,  shapes.size());
  
  ASSERT_EQ(128,  shapes.at("test_0").GetWidth());
  ASSERT_EQ(128,  shapes.at("test_0").GetHeight());
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
