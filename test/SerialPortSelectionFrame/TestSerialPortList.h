#ifndef TESTSERIALPORTLIST_H
#define TESTSERIALPORTLIST_H
#include <gmock/gmock.h>
#include "interface/ISerialPortList.h"

class TestSerialPortList : public ISerialPortList {
public:
  MOCK_METHOD0(getPorts, std::list<std::string>(void));
};

#endif /* TESTSERIALPORTLIST_H */

