#include "control/BlueprintListPanel.h"

#include <string>
#include <map>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>

#include "control/BlueprintButton.h"

BlueprintListPanel::BlueprintListPanel(wxWindow* parent, wxWindowID id) :
wxScrolled<wxPanel>(parent, id) {
}

void BlueprintListPanel::setDisplayHandler(IBlueprintDisplayHandler* handler) {
  this->handler = handler;
}

/*
 * Load shape gallery of blueprints.
 * Must called after setDisplayHandler().
 */
void BlueprintListPanel::loadBlueprints(IShapeGallery* gallery) {
  wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

  std::map <std::string, wxBitmap> list = gallery->getShapes();

  // show content:
  for (std::map<std::string, wxBitmap>::iterator it = list.begin(); it != list.end(); ++it) {
    BlueprintButton* bitmapBox = new BlueprintButton(this, wxID_ANY, it->second);
    bitmapBox->init(it->first, this->handler);
    sizer->Add(bitmapBox, 0, wxALL, 3);
  }

  this->SetMinSize(wxSize(150, 150));
  this->SetSizer(sizer);
  this->FitInside();
  this->SetScrollRate(5, 5);

}