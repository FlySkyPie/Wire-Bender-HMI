#include "frame/ProgressFrame.h"

#include <wx/sizer.h>

/*
 * Initialize the frame, create control components.
 */
ProgressFrame::ProgressFrame() :
wxFrame(NULL, wxID_ANY, "Hello World", wxDefaultPosition, wxSize(400, 400),
wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX) {
  this->Bind(wxEVT_CLOSE_WINDOW, &ProgressFrame::OnClose, this);
  
  //control components
  this->gauge = new wxGauge(this, wxID_ANY, 100, wxPoint(40, 40), wxSize(320, 20));
  this->button = new wxButton(this, wxID_ANY, wxT("Stop"), wxPoint(150, 120), wxDefaultSize, 0);
  this->textCtrl = new wxTextCtrl(this, wxID_ANY, "",
          wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL);

  this->Connect(this->button->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(ProgressFrame::buttonClick));

  // typesetting
  wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

  sizer->Add(gauge, 0, wxALIGN_CENTER | wxALL, 3);
  sizer->Add(button, 0, wxALIGN_CENTER | wxALL, 3);
  mainSizer->Add(sizer, 1, wxALL);
  mainSizer->Add(textCtrl, 7, wxEXPAND | wxALL, 3);

  this->SetSizer(mainSizer);
}

/*
 * Set the interface which handle switch frame.
 */
void ProgressFrame::setFrameSwitchHandler(IFrameSwitchHandler* handler) {
  this->handler = handler;
}

/*
 * Create a Factory which can created ProduceManager.
 * Must called this after setFrameSwitchHandler.
 */
void ProgressFrame::createProductFactory(ISerialPortCommunicator * communicator) {
  this->factory = new ProduceManagerFactory();
  this->factory->setProgressPanel(this);
  this->factory->setCommunicator(communicator);
  this->factory->setFrameSwitchHandler(this->handler);
}

void ProgressFrame::setExit(IExit * exit) {
  this->exit = exit;
}

/*
 * Start produce.
 */
void ProgressFrame::startProduce(std::string name, std::string code) {
  this->productName = name;
  this->update(0);

  this->textCtrl->ChangeValue("");

  this->produceManager = this->factory->getProduceManager(code);
  this->produceManager->startProduce();
}

/*
 * Update progress.
 */
void ProgressFrame::update(float progress) {
  int progressNumber = ceil(100 * progress);
  this->gauge->SetValue(progressNumber);
  std::string title = "[" + this->productName + "] Producing...(" + std::to_string(progressNumber) + "%)";
  this->SetTitle(title);
}

/*
 * Report what command has sending to machine.
 */
void ProgressFrame::reportCommand(std::string command) {
  command = "Working on: " + command + " ...";
  this->textCtrl->AppendText(command);
}

/*
 * The command finished signal has been get,
 * report on GUI.
 */
void ProgressFrame::reportCheck() {
  this->textCtrl->AppendText("Ok\n");
}

/*
 * When the stop button pressed.
 */
void ProgressFrame::buttonClick(wxCommandEvent & event) {
  this->produceManager->stopProduce();
  this->handler->stopProduce();
}

void ProgressFrame::OnClose(wxCloseEvent &event) {
  this->exit->exit();
}