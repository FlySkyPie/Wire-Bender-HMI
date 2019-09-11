#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H
#include <string>
#include <wx/app.h>

#include "interface/IFrameSwitchHandler.h"
#include "interface/IExit.h"
#include "frame/MenuFrame.h"
#include "frame/ProgressFrame.h"
#include "frame/SerialPortSelectionFrame.h"
#include "work/SerialPortManager.h"

class MainApplication : public wxApp, public IFrameSwitchHandler ,public IExit{
public:
  bool OnInit();

  void setPort(std::string path);
  void stopProduce();
  void startProduce(std::string name, std::string code);
  
  void exit();

private:
  ProgressFrame *progressFrame;
  SerialPortSelectionFrame * portSelectionFrame;
  MenuFrame * menuFrame;

  SerialPortManager * serialPortManager;

};
#endif /* MAINAPPLICATION_H */