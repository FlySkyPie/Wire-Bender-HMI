#ifndef ISHAPEGALLERY_H
#define ISHAPEGALLERY_H
#include <string>
#include <map>
#include <wx/bitmap.h>

/*
 * The interface which get shape of blueprints.
 */
class IShapeGallery {
public:
  virtual std::map<std::string, wxBitmap>getShapes() = 0;
};

#endif