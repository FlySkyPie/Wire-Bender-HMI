#ifndef IPROGRESSPANEL_H
#define IPROGRESSPANEL_H
#include <string>

/*
 * The interface which report current working and update progress to GUI panel.
 */
class IProgressPanel {
public:
  virtual void update(float progress) = 0;
  virtual void reportCommand(std::string command) = 0;
  virtual void reportCheck() = 0;
};

#endif /* IPROGRESSPANEL_H */