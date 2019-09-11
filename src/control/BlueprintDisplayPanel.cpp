#include "control/BlueprintDisplayPanel.h"

#include <wx/sizer.h>

BlueprintDisplayPanel::BlueprintDisplayPanel(wxWindow *parent, wxWindowID id) :
wxPanel(parent, id) {

}

/*
 * Initialize the panel, create control components.
 */
void BlueprintDisplayPanel::init(IBlueprintStorage * storage) {
  this->storage = storage;

  //get default blueprint
  std::string info = storage->getInfo("test");
  std::string code = storage->getCode("test");
  wxBitmap preview = storage->getPreview("test");

  //control component
  this->previewImage = new wxStaticBitmap(this, wxID_ANY, preview);

  this->infoTextBox = new wxTextCtrl(this, wxID_ANY, info,
          wxDefaultPosition, wxSize(0, 110), wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL);

  this->codeTextBox = new wxTextCtrl(this, wxID_ANY, code,
          wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL);

  this->startButton = new wxButton(this, wxID_ANY, "Start Produce");

  this->Connect(this->startButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(BlueprintDisplayPanel::buttonClick));

  // typesetting
  wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* verticalSizer = new wxBoxSizer(wxVERTICAL);

  horizontalSizer->Add(this->previewImage, 1, wxALL, 5);
  horizontalSizer->Add(verticalSizer, 1, 0, 0);

  verticalSizer->Add(this->infoTextBox, 2, wxEXPAND | wxALL, 5);
  verticalSizer->Add(this->codeTextBox, 2, wxEXPAND | wxALL, 5);
  verticalSizer->Add(this->startButton, 1, wxEXPAND | wxALL, 5);

  this->SetMinSize(wxSize(300, 600));
  this->SetSizer(horizontalSizer);
  this->FitInside();
}

void BlueprintDisplayPanel::setFrameSwitchHandler(IFrameSwitchHandler * handler) {
  this->handler = handler;
}

void BlueprintDisplayPanel::loadBlueprint(std::string name) {
  this->blueprintName = name;
  std::string info = storage->getInfo(name);
  std::string code = storage->getCode(name);
  wxBitmap preview = storage->getPreview(name);

  this->previewImage->SetBitmap(preview);
  this->infoTextBox->SetValue(info);
  this->codeTextBox->SetValue(code);
}

void BlueprintDisplayPanel::buttonClick(wxCommandEvent &event) {
  std::string name, code;
  name = this->blueprintName;
  code = this->codeTextBox->GetValue().ToStdString();
  this->handler->startProduce(name, code);
}