#include "frame/MenuFrame.h"

#include <iterator>
#include <vector>
#include <iostream>

#include <wx/splitter.h>
#include <wx/sizer.h>

#include "work/BlueprintStorage.h"
#include "control/BlueprintDisplayPanel.h"
#include "control/BlueprintListPanel.h"

MenuFrame::MenuFrame() :
wxFrame(NULL, wxID_ANY, "Wire Bender Machine HMI", wxDefaultPosition, wxSize(820, 500),
wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX) {
  this->Bind(wxEVT_CLOSE_WINDOW, &MenuFrame::OnClose, this);
}

void MenuFrame::init(IFrameSwitchHandler * handler) {
  wxSplitterWindow* splitterWindow = new wxSplitterWindow(this, wxID_ANY);
  BlueprintStorage * blueprintStorage = new BlueprintStorage();

  BlueprintDisplayPanel *displayPanel =
          new BlueprintDisplayPanel(splitterWindow, wxID_ANY);
  displayPanel->init(blueprintStorage);
  displayPanel->setFrameSwitchHandler(handler);

  BlueprintListPanel *listPanel =
          new BlueprintListPanel(splitterWindow, wxID_ANY);
  listPanel->setDisplayHandler(displayPanel);
  listPanel->loadBlueprints(blueprintStorage);


  splitterWindow->SetSashGravity(0.0);
  splitterWindow->SetMinimumPaneSize(50);
  splitterWindow->SplitHorizontally(displayPanel, listPanel, 300);

  wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  mainSizer->Add(splitterWindow, 1, wxEXPAND);
  this->SetSizer(mainSizer);
}

void MenuFrame::setExit(IExit * exit) {
  this->exit = exit;
}

void MenuFrame::OnClose(wxCloseEvent &event) {
  this->exit->exit();
}