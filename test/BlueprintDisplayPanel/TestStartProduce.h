#ifndef TESTSTARTPRODUCE_H
#define TESTSTARTPRODUCE_H
#include <string>
#include <gmock/gmock.h>
#include "interface/IStartProduce.h"

class TestStartProduce : public IStartProduce {
public:
  MOCK_METHOD2(startProduce, void(std::string name, std::string code));
};

#endif /* TESTSTARTPRODUCE_H */

