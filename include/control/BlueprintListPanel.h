#ifndef BLUEPRINTLISTPANEL_H
#define BLUEPRINTLISTPANEL_H
#include <wx/scrolwin.h>
#include <wx/panel.h>

#include "interface/IBlueprintDisplayHandler.h"
#include "interface/IShapeGallery.h"

class BlueprintListPanel : public wxScrolled<wxPanel> {
public:
  BlueprintListPanel(wxWindow* parent, wxWindowID id);
  void setDisplayHandler(IBlueprintDisplayHandler* handler);
  void loadBlueprints(IShapeGallery* gallery);

private:
  IBlueprintDisplayHandler* handler;
};
#endif /* BLUEPRINTLISTPANEL_H */