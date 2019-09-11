#ifndef ISERIALPORTCOMMUNICATOR_H
#define ISERIALPORTCOMMUNICATOR_H
#include <string>

/*
 * The interface which communicate with com port.
 */
class ISerialPortCommunicator {
public:
  virtual std::string readline() = 0;
  virtual void send(std::string text) = 0;

};

#endif /* ISERIALPORTREADER_H */