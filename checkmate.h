#ifndef CHECKMATE_H
#define CHECKMATE_H

#include <string>

class Checkmate {
  std::string color;
public:
  Checkmate(std::string color);
  std::string getColor();
  ~Checkmate() = default;
};

#endif
