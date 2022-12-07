#ifndef INVALIDMOVE_H
#define INVALIDMOVE_H

#include <string>

class InvalidMove {
  std::string msg;
public:
  explicit InvalidMove(std::string msg);
  std::string getMsg();
  ~InvalidMove() = default;
};

#endif
