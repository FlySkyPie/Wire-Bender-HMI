#ifndef TESTBLUEPRINTSTORAGE_H
#define TESTBLUEPRINTSTORAGE_H
#include <gmock/gmock.h>
#include <string>
#include <wx/bitmap.h>

#include "interface/IBlueprintStorage.h"
#include "interface/IBlueprint.h"

class TestBlueprintStorage : public IBlueprintStorage {
public:
  MOCK_METHOD1(getInfo, std::string(std::string name));
  MOCK_METHOD1(getCode, std::string(std::string name));

  MOCK_METHOD1(getPreview, wxBitmap(std::string name));
  MOCK_METHOD1(getShape, wxBitmap(std::string name));

  MOCK_METHOD1(getBlueprint, IBlueprint * (std::string name));
};
#endif