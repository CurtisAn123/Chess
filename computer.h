#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
public:
  explicit Computer(char type);
  void playBestMove();
  ~Computer();
};

#endif
