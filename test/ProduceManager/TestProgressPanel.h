#ifndef TESTPROGRESSPANEL_H
#define TESTPROGRESSPANEL_H
#include <string>
#include <gmock/gmock.h>
#include "interface/IProgressPanel.h"

class TestProgressPanel : public IProgressPanel {
public:
  MOCK_METHOD1(update, void(float progress));
  MOCK_METHOD1(reportCommand, void(std::string command));
  MOCK_METHOD0(reportCheck, void(void));
};


#endif /* TESTPROGRESSPANEL_H */

