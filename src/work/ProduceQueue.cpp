#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "work/ProduceQueue.h"

ProduceQueue::ProduceQueue(std::string code) {
  //split the code line by line
  std::stringstream ss(code);
  std::string token;
  while (std::getline(ss, token, '\n')) {
    if (token == "") {
      continue;
    }
    this->commandList.push_back(token);
    this->size +=1;
  }
}

/*
 * Get a command, and remove it from queue.
 */
std::string ProduceQueue::getCommand() {
  if (this->commandList.size() == 0) {
    return "";
  }

  std::string command = this->commandList.front();
  this->commandList.pop_front();
  this->loss +=1;
  return command;
}

/*
 * Checking is queue finished?
 */
bool ProduceQueue::isFinished() {
  if (this->commandList.size() == 0) {
    return true;
  } else {
    return false;
  }
}

 float ProduceQueue::getProgress(){
   return 1.0 * this->loss / this->size;
 }