#ifndef BLUEPRINTSTORAGE_H
#define BLUEPRINTSTORAGE_H
#include <string>
#include <map>
#include <wx/bitmap.h>

#include "interface/IShapeGallery.h"
#include "interface/IBlueprintStorage.h"

class BlueprintStorage : public IShapeGallery, public IBlueprintStorage {
public:
  BlueprintStorage();

  std::map<std::string, wxBitmap>getShapes();

  std::string getInfo(std::string name);
  std::string getCode(std::string name);
  wxBitmap getPreview(std::string name);
  wxBitmap getShape(std::string name);

private:
  std::string blueprintPath;
  std::string getAppRootPath();
  std::string readFile(std::string fileName);
};
#endif /* BLUEPRINTSTORAGE_H */