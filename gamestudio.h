#ifndef GAMESTUDIO_H
#define GAMESTUDIO_H
#include <iostream>
#include "subject.h"
#include "piece.h"
#include "player.h"

class GameBoard;

class GameStudio : public Subject {
  int whiteWins, blackWins;
  std::ostream &out = std::cout;
  Player * white;
  Player * black;
  GameBoard *Board;

 public:
  GameStudio();

  GameBoard *&getBoard();
  void setBoard(GameBoard * Board);

  void setWhite(Player * player);
  void setBlack(Player * player);
  Player *&getWhite();
  Player *&getBlack();

  void movePiece(int startRow, int startCol, int endRow, int endCol, std::string color);

  void reset();
  void render();
  char getState(int row, int col) const override;
  ~GameStudio();
};

#endif
