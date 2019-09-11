#include "application/MainApplication.h"

 #include <X11/Xlib.h>

bool MainApplication::OnInit() {
  XInitThreads();
  
  this->serialPortManager = new SerialPortManager();

  this->portSelectionFrame = new SerialPortSelectionFrame();
  this->portSelectionFrame->setFrameSwitchHandler(this);
  this->portSelectionFrame->loadPortList(this->serialPortManager);
  this->portSelectionFrame->setExit(this);

  this->progressFrame = new ProgressFrame();
  this->progressFrame->setFrameSwitchHandler(this);
  this->progressFrame->createProductFactory(this->serialPortManager);
  this->progressFrame->setExit(this);

  this->menuFrame = new MenuFrame();
  this->menuFrame->init(this);
  this->menuFrame->setExit(this);

  this->portSelectionFrame->Show();
  //this->menuFrame->Show(true);  //test
  //this->progressFrame->Show(true); //test
  return true;
}

void MainApplication::setPort(std::string path) {
  this->serialPortManager->setPort(path);
  this->portSelectionFrame->Hide();
  this->menuFrame->Show();
}

void MainApplication::stopProduce() {
  this->progressFrame->Hide();
  this->menuFrame->Show();
}

void MainApplication::startProduce(std::string name, std::string code) {
  this->progressFrame->startProduce(name, code);

  this->menuFrame->Hide();
  this->progressFrame->Show();
}

void MainApplication::exit(){
  this->progressFrame->Destroy();
  this->menuFrame->Destroy();
  this->portSelectionFrame->Destroy();
}