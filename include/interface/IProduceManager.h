#ifndef IPRODUCEMANAGER_H
#define IPRODUCEMANAGER_H
#include <thread>   

/*
 * The interface of ProduceManager.
 * The produce process should bring to another thread.
 */
class IProduceManager {
public:
  virtual void stopProduce() = 0;
  virtual void startProduce() = 0;
};

#endif /* IPRODUCEMANAGER_H */