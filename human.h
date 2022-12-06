#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
public:
  explicit Human(char type);
  ~Human();
};

#endif
