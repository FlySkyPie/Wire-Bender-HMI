#ifndef PRODUCEMANAGERFACTORY_H
#define PRODUCEMANAGERFACTORY_H
#include <string>

#include "interface/IProgressPanel.h"
#include "interface/ISerialPortCommunicator.h"
#include "interface/IProduceManager.h"
#include "interface/IFrameSwitchHandler.h"

class ProduceManagerFactory {
public:
  ProduceManagerFactory();

  void setProgressPanel(IProgressPanel * panel);
  void setCommunicator(ISerialPortCommunicator * communicator);
  void setFrameSwitchHandler(IFrameSwitchHandler * handler);

  IProduceManager * getProduceManager(std::string code);

private:
  IProgressPanel * panel;
  ISerialPortCommunicator * communicator;
  IFrameSwitchHandler * handler;
};

#endif /* PRODUCEMANAGERFACTORY_H */