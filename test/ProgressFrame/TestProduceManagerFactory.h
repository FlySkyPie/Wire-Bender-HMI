#ifndef TESTPRODUCEMANAGERFACTORY_H
#define TESTPRODUCEMANAGERFACTORY_H
#include <gmock/gmock.h>
#include "interface/IProduceManagerFactory.h"

class TestProduceManagerFactory : public IProduceManagerFactory {
public:
  MOCK_METHOD1(getProduceManager, IProduceManager*(std::string code));
};

#endif /* TESTPRODUCEMANAGERFACTORY_H */

