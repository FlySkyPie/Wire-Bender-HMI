#ifndef SERIALPORTSELECTIONFRAME_H
#define SERIALPORTSELECTIONFRAME_H
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/button.h>

#include "interface/IFrameSwitchHandler.h"
#include "interface/ISerialPortList.h"
#include "interface/IExit.h"

/*
 * The Frame which show selections of com port.
 */

class SerialPortSelectionFrame : public wxFrame {
public:
  SerialPortSelectionFrame();
  void setFrameSwitchHandler(IFrameSwitchHandler* handler);
  void loadPortList(ISerialPortList * portList);
  void setExit(IExit * exit);
private:
  IFrameSwitchHandler* switchHandler;
  wxButton *button;
  wxListBox * listBox;
  
  IExit * exit;

  void buttonClicked(wxCommandEvent &event);
  void OnClose(wxCloseEvent &event);
};
#endif /* SERIALPORTSELECTIONFRAME_H */