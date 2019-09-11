#include "frame/SerialPortSelectionFrame.h"

#include <string>
#include <list>
#include <iostream>

#include <wx/arrstr.h>  //wxArrayString
#include <wx/sizer.h>

SerialPortSelectionFrame::SerialPortSelectionFrame()
: wxFrame(NULL, wxID_ANY, "Select the device port", wxDefaultPosition, wxSize(400, 400),
wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX) {
  this->Bind(wxEVT_CLOSE_WINDOW, &SerialPortSelectionFrame::OnClose, this);
  
  //controls
  this->listBox = new wxListBox(this, wxID_ANY, wxPoint(20, 20),
          wxSize(200, 60));
  this->button = new wxButton(this, wxID_ANY, "Select",
          wxPoint(20, 100), wxDefaultSize, 0);

  this->Connect(this->button->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(SerialPortSelectionFrame::buttonClicked));

  // typesetting
  wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  mainSizer->Add(listBox, 7, wxEXPAND | wxALL, 3);
  mainSizer->Add(button, 1, wxEXPAND | wxALL, 3);

  this->SetSizer(mainSizer);
}

void SerialPortSelectionFrame::setFrameSwitchHandler(IFrameSwitchHandler* handler) {
  this->switchHandler = handler;
}

void SerialPortSelectionFrame::loadPortList(ISerialPortList * portList) {
  //get list of port
  //wxArrayString *selection = new wxArrayString;
  std::list <std::string> list = portList->getPorts();
  std::list<std::string>::iterator it = list.begin();

  while (it != list.end()) {
    std::string portName = *it++;
    this->listBox->Append(portName);
    //selection->Add(portName);
  }

  //this->listBox->Append(selection);
}

void SerialPortSelectionFrame::buttonClicked(wxCommandEvent &event) {
  std::string portName = this->listBox->GetStringSelection().ToStdString();
  this->switchHandler->setPort(portName);
}

void SerialPortSelectionFrame::OnClose(wxCloseEvent &event) {
  this->exit->exit();
}

void SerialPortSelectionFrame::setExit(IExit * exit){
  this->exit = exit;
}