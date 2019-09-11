#ifndef IFRAMESWITCHHANDLER_H
#define IFRAMESWITCHHANDLER_H
#include <string>

/*
 * The interface which provided frame switching functions.
 */
class IFrameSwitchHandler {
public:
  virtual void setPort(std::string path) = 0;
  virtual void stopProduce() = 0;
  virtual void startProduce(std::string name, std::string code) = 0;
};

#endif /* IFRAMESWITCHHANDLER_H */

