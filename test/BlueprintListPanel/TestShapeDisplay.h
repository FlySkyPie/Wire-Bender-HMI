#ifndef TESTSHAPEDISPLAY_H
#define TESTSHAPEDISPLAY_H
#include <gmock/gmock.h>
#include <string>
#include <wx/bitmap.h>
#include "interface/IShapeDisplay.h"

class TestShapeDisplay:public IShapeDisplay {
public:
  MOCK_METHOD0(getShapes, std::map<std::string, wxBitmap>(void));
};

#endif

