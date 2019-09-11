#ifndef MENUFRAME_H
#define MENUFRAME_H
#include <wx/frame.h>
#include "interface/IFrameSwitchHandler.h"
#include "interface/IExit.h"

class MenuFrame : public wxFrame {
public:
  MenuFrame();
  void init(IFrameSwitchHandler * handler);
  
  void setExit(IExit * exit);
private:
  void OnClose(wxCloseEvent &event);
  
  IExit * exit;
};
#endif /* MENUFRAME_H */