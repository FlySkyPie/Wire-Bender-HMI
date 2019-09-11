#ifndef TESTSERIALPORTCONFIGURER_H
#define TESTSERIALPORTCONFIGURER_H
#include <gmock/gmock.h>
#include "interface/ISerialPortConfigurer.h"

class TestSerialPortConfigurer : public ISerialPortConfigurer {
public:
  MOCK_METHOD1(setPort, void(std::string path));
};

#endif /* TESTSERIALPORTCONFIGURER_H */

