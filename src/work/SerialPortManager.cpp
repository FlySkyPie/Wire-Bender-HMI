#include "work/SerialPortManager.h"

#include <iostream> //test
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <serial/serial.h>

SerialPortManager::SerialPortManager() {
}

/*
 * Read string until '\n' from COM port buffer,
 * if there are not '\n' yet then save to software buffer and return empty string.
 */
std::string SerialPortManager::readline() {
  std::string text;
  text = this->device->readline();

  size_t found = text.find("\n");
  if (found == std::string::npos) {
    this->buffer += text;
    return "";
  }
  text.erase(std::remove(text.begin(), text.end(), '\n'), text.end());

  text = this->buffer + text;
  this->buffer = "";
  
  //std::cout << "readed: " << text << "\n";
  return text;
}

/*
 * Send a message to COM port.
 */
void SerialPortManager::send(std::string text) {
  this->device->write(text);
}

void SerialPortManager::setPort(std::string path) {
  this->path = path;
  this->device = new serial::Serial(this->path, 9600, serial::Timeout::simpleTimeout(1000));

  //waitting system set and prepared.
  usleep(1000000);

  //clean the buffer
  this->device->read(65536);
}

/*
 * Get list of COM ports.
 */
std::list<std::string> SerialPortManager::getPorts() {
  std::list<std::string> list;
  std::vector<serial::PortInfo> devices_found = serial::list_ports();
  std::vector<serial::PortInfo>::iterator iter = devices_found.begin();

  while (iter != devices_found.end()) {
    serial::PortInfo device = *iter++;
    list.push_back(device.port);
  }
  return list;
}