#ifndef ISERIALPORTLIST_H
#define ISERIALPORTLIST_H
#include <string>
#include <list>

/*
 * The interface which get list of com port that is available.
 */
class ISerialPortList {
public:
  virtual std::list<std::string>getPorts() = 0;
};

#endif /* ISERIALPORTLIST_H */