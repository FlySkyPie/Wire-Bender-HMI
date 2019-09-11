#ifndef BLUEPRINTBUTTON_H
#define BLUEPRINTBUTTON_H
#include <string>
#include <wx/statbmp.h>
#include <wx/event.h>

#include "interface/IBlueprintDisplayHandler.h"

class BlueprintButton : public wxStaticBitmap {
public:
  BlueprintButton(wxWindow *parent, wxWindowID id, const wxBitmap &label);
  void init(std::string name, IBlueprintDisplayHandler* handler);

private:
  std::string name;
  IBlueprintDisplayHandler* handler;
  
  void onClicked(wxCommandEvent& event);
};
#endif /* BLUEPRINTBUTTON_H */