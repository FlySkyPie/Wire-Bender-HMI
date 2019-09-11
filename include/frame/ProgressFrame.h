#ifndef PROGRESSFRAME_H
#define PROGRESSFRAME_H
#include <string>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/button.h>

#include "interface/IProgressPanel.h"
#include "interface/ISerialPortCommunicator.h"
#include "interface/IFrameSwitchHandler.h"
#include "interface/IExit.h"

#include "work/ProduceManagerFactory.h"

class ProgressFrame : public IProgressPanel, public wxFrame {
public:
  ProgressFrame();

  void setFrameSwitchHandler(IFrameSwitchHandler* handler);

  void createProductFactory(ISerialPortCommunicator * communicator);
  void setExit(IExit * exit);

  void startProduce(std::string name, std::string code);

  void update(float progress);
  void reportCommand(std::string command);
  void reportCheck();
private:
  //controls
  wxGauge *gauge;
  wxButton * button;
  wxTextCtrl * textCtrl;

  //product
  std::string productName;
  //std::thread* produceThread;
  IProduceManager* produceManager;

  //
  IFrameSwitchHandler* handler;
  ProduceManagerFactory * factory;
  
  IExit * exit;

  void buttonClick(wxCommandEvent & event);
  void OnClose(wxCloseEvent &event);
};
#endif /* PROGRESSFRAME_H */