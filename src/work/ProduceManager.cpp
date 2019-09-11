#include "work/ProduceManager.h"

#include <iostream> //test
#include <wx/event.h>
#include <wx/timer.h>

/*
 * Create ProduceQueue to parse the code.
 */
ProduceManager::ProduceManager(std::string code) {
  this->queue = new ProduceQueue(code);
  this->busy = false;

  this->timer = new wxTimer(this, wxID_ANY);
  this->Connect(this->timer->GetId(), wxEVT_TIMER, wxTimerEventHandler(ProduceManager::main), NULL, this);
}

/*
 * Setting the ProgressPanel.
 */
void ProduceManager::setProgressPanel(IProgressPanel* panel) {
  this->progressPanel = panel;
}

/*
 * Setting the SerialPortCommunicator.
 */
void ProduceManager::setCommunicator(ISerialPortCommunicator* communicator) {
  this->communicator = communicator;
}

void ProduceManager::setFrameSwitchHandler(IFrameSwitchHandler * handler) {
  this->handler = handler;
}

/*
 * Create a new thread and return it, which processing produce.
 */
void ProduceManager::startProduce() {
  this->timer->Start(100);
}

void ProduceManager::stopProduce() {
  this->timer->Stop();
}

/*
 * The main process of production.
 */
void ProduceManager::main(wxTimerEvent& event) {
  if (!this->busy) {
    std::string command = this->queue->getCommand();

    this->progressPanel->reportCommand(command);
    this->communicator->send(command);
    this->busy = true;
    return;
  }

  if (this->communicator->readline() == "ok") {
    float progress = this->queue->getProgress();
    this->progressPanel->update(progress);
    this->progressPanel->reportCheck();
    this->busy = false;

    if (this->queue->isFinished()) {
      this->timer->Stop();
      this->handler->stopProduce();
    }
  }
}