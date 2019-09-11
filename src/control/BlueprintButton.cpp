#include "control/BlueprintButton.h"

BlueprintButton::BlueprintButton(wxWindow *parent, wxWindowID id, const wxBitmap &label):
wxStaticBitmap(parent, id, label){

}

void BlueprintButton::init(std::string name, IBlueprintDisplayHandler* handler) {
  this->name = name;
  this->handler = handler;
  this->Connect(this->GetId(), wxEVT_LEFT_DOWN, wxCommandEventHandler(BlueprintButton::onClicked));
}

void BlueprintButton::onClicked(wxCommandEvent& event) {
  this->handler->loadBlueprint(this->name);
}