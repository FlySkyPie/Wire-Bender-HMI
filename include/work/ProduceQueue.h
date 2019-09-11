#ifndef PRODUCEQUEUE_H
#define PRODUCEQUEUE_H
#include <string>
#include <list>
#include <cstdint>

class ProduceQueue {
public:
  ProduceQueue(std::string code);

  std::string getCommand();
  bool isFinished();
  float getProgress();

private:
  std::list <std::string> commandList;
  uint32_t size = 0;
  uint32_t loss = 0;

};

#endif /* PRODUCEQUEUE_H */