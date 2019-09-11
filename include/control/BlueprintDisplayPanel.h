#ifndef BLUEPRINTDISPLAYPANEL_H
#define BLUEPRINTDISPLAYPANEL_H
#include <string>

#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/button.h>

#include "interface/IBlueprintDisplayHandler.h"
#include "interface/IFrameSwitchHandler.h"
#include "interface/IBlueprintStorage.h"

class BlueprintDisplayPanel : public wxPanel, public IBlueprintDisplayHandler {
public:
  BlueprintDisplayPanel(wxWindow *parent, wxWindowID id);
  void init(IBlueprintStorage * storage);

  void setFrameSwitchHandler(IFrameSwitchHandler * handler);

  void loadBlueprint(std::string name);

private:
  //control components
  wxStaticBitmap * previewImage;
  wxTextCtrl * infoTextBox;
  wxTextCtrl *codeTextBox;
  wxButton * startButton;

  IFrameSwitchHandler* handler;
  IBlueprintStorage* storage;

  std::string blueprintName;

  void buttonClick(wxCommandEvent &event);
};
#endif /* BLUEPRINTDISPLAYPANEL_H */