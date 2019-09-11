#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H
#include <list>
#include <string>
#include <serial/serial.h>

#include "interface/ISerialPortList.h"
#include "interface/ISerialPortCommunicator.h"

class SerialPortManager : public ISerialPortList, public ISerialPortCommunicator {
public:
  SerialPortManager();

  void setPort(std::string path);

  std::string readline();
  void send(std::string text);
  std::list<std::string>getPorts();
private:
  std::string path;
  std::string buffer;
  serial::Serial * device;
};

#endif /* SERIALPORTMANAGER_H */