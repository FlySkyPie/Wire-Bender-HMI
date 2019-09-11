#ifndef TESTSERIALPORTCOMMUNICATOR_H
#define TESTSERIALPORTCOMMUNICATOR_H
#include <string>
#include <gmock/gmock.h>
#include "interface/ISerialPortCommunicator.h"

class TestSerialPortCommunicator : public ISerialPortCommunicator {
public:
  MOCK_METHOD0(readline, std::string(void));
  MOCK_METHOD1(send, void(std::string text));
};

#endif /* TESTSERIALPORTCOMMUNICATOR_H */