#ifndef GAMESTUDIO_H
#define GAMESTUDIO_H
#include <iostream>
#include "subject.h"
#include "piece.h"

class GameBoard;

class GameStudio : public Subject {

  std::ostream &out = std::cout;

  GameBoard *Board;

 public:
  explicit GameStudio(GameBoard *gameBoard): Board{gameBoard} {}

  GameBoard *&getBoard() { return Board; }

  void movePiece(int startRow, int startCol, int endRow, int endCol, std::string color);

  void reset();
  void render();
  char getState(int row, int col) const override;
  ~GameStudio();
};

#endif
