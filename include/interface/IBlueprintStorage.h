#ifndef IBLUEPRINTSTORAGE_H
#define IBLUEPRINTSTORAGE_H
#include <string>
#include <wx/bitmap.h>

/*
 * The interface which access file system to get blueprint.
 */
class IBlueprintStorage {
public:
  virtual std::string getInfo(std::string name) = 0;
  virtual std::string getCode(std::string name) = 0;
  virtual wxBitmap getPreview(std::string name) = 0;
  virtual wxBitmap getShape(std::string name) = 0;
};
#endif