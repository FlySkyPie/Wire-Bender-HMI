#include "work/ProduceManagerFactory.h"
#include "work/ProduceManager.h"

ProduceManagerFactory::ProduceManagerFactory() {
}

/*
 * Setting the ProgressPanel.
 */
void ProduceManagerFactory::setProgressPanel(IProgressPanel * panel) {
  this->panel = panel;
}

/*
 * Setting the SerialPortCommunicator.
 */
void ProduceManagerFactory::setCommunicator(ISerialPortCommunicator * communicator) {
  this->communicator = communicator;
}

void ProduceManagerFactory::setFrameSwitchHandler(IFrameSwitchHandler * handler){
  this->handler = handler;
}

/*
 * Create a new ProduceManager and return it.
 */
IProduceManager * ProduceManagerFactory::getProduceManager(std::string code) {
  ProduceManager* produceManager = new ProduceManager(code);
  produceManager->setProgressPanel(this->panel);
  produceManager->setCommunicator(this->communicator);
  produceManager->setFrameSwitchHandler(this->handler);
  return produceManager;
}