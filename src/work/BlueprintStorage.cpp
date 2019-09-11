#include "work/BlueprintStorage.h"

#include <unistd.h>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

BlueprintStorage::BlueprintStorage() {
  this->blueprintPath = this->getAppRootPath() + "/blueprint";
}

/*
 * Get shape of blueprints.
 */
std::map<std::string, wxBitmap>BlueprintStorage::getShapes() {
  std::map<std::string, wxBitmap> map;

  for (const auto & entry : fs::directory_iterator(this->blueprintPath)) {
    std::string filename = entry.path().filename().string();
    wxBitmap image = this->getShape(filename);
    map.insert(std::pair<std::string, wxBitmap>(filename, image));
  }
  return map;
}

/*
 * Get information fo certain blueprint.
 */
std::string BlueprintStorage::getInfo(std::string name) {
  std::string fileName = this->blueprintPath + "/" + name + "/info.txt";
  return this->readFile(fileName);
}

/*
 * Get code of certain blueprint.
 */
std::string BlueprintStorage::getCode(std::string name) {
  std::string fileName = this->blueprintPath + "/" + name + "/wbcode.wbcode";
  return this->readFile(fileName);
}

/*
 * Get preview image of certain blueprint.
 */
wxBitmap BlueprintStorage::getPreview(std::string name) {
  std::string fileName = this->blueprintPath + "/" + name + "/preview.png";
  wxBitmap image(fileName, wxBITMAP_TYPE_PNG);
  return image;
}

/*
 * Get shape image of certain blueprint.
 */
wxBitmap BlueprintStorage::getShape(std::string name) {
  std::string fileName = this->blueprintPath + "/" + name + "/shape.png";
  wxBitmap image(fileName, wxBITMAP_TYPE_PNG);
  return image;
}

/*
 * Get content from a file.
 */
std::string BlueprintStorage::readFile(std::string fileName) {
  std::ifstream ifs(fileName);
  std::string content;
  content.assign((std::istreambuf_iterator<char>(ifs)),
          (std::istreambuf_iterator<char>()));
  return content;
}

/*
 * Get absolute path of this application.
 */
std::string BlueprintStorage::getAppRootPath() {
  char szBuf[1024];
  int nCount;

  memset(szBuf, 0, sizeof (szBuf));
  nCount = readlink("/proc/self/exe", szBuf, 1024);
  if (nCount < 0 || nCount >= 1024) {
    throw "Get path failed!";
  }
  szBuf[nCount] = '\0';
  std::string str(szBuf);
  std::size_t found = str.find_last_of("/");
  return str.substr(0, found);
}