#ifndef TESTSTOPPRODUCE_H
#define TESTSTOPPRODUCE_H
#include <gmock/gmock.h>
#include "interface/IStopProduce.h"

class TestStopProduce : public IStopProduce {
public:
  MOCK_METHOD0(stopProduce, void(void));
};

#endif /* TESTSTOPPRODUCE_H */

