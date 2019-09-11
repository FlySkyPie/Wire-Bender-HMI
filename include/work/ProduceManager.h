#ifndef PRODUCEMANAGER_H
#define PRODUCEMANAGER_H
#include <string>
#include <thread>

#include <wx/event.h>
#include <wx/timer.h>

#include "interface/IProduceManager.h"
#include "interface/IProgressPanel.h"
#include "interface/ISerialPortCommunicator.h"
#include "interface/IFrameSwitchHandler.h"
#include "work/ProduceQueue.h"

class ProduceManager : public IProduceManager , public wxEvtHandler {
public:
  ProduceManager(std::string code);

  void setProgressPanel(IProgressPanel* panel);
  void setCommunicator(ISerialPortCommunicator* communicator);
  void setFrameSwitchHandler(IFrameSwitchHandler * handler);

  void stopProduce();
  void startProduce();
private:
   wxTimer *timer;
  
  ProduceQueue * queue;
  IProgressPanel * progressPanel;
  ISerialPortCommunicator * communicator;
  IFrameSwitchHandler * handler;

  bool busy;
  void main(wxTimerEvent& event);
};

#endif /* PRODUCEMANAGER_H */