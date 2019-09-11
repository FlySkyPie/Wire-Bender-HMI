#ifndef TESTBLUEPRINTDISPLAY_H
#define TESTBLUEPRINTDISPLAY_H
#include <gmock/gmock.h>
#include "interface/IBlueprintDisplay.h"

class TestBlueprintDisplay : public IBlueprintDisplay {
public:
  MOCK_METHOD1(load, void(std::string name));
};
#endif