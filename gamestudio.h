#ifndef GAMESTUDIO_H
#define GAMESTUDIO_H
#include <iostream>
#include "subject.h"

class GameBoard;

class GameStudio : public Subject {

  std::ostream &out = std::cout;

  GameBoard *Board;

 public:
  explicit GameStudio(GameBoard *Board): Board{Board} {}

  GameBoard *&Board() { return Board; }
  void reset();
  void render();
  void animate(int numTicks);
  char getState(int row, int col) const override;
  ~GameStudio();
};

#endif
