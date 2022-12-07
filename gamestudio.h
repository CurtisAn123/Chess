#ifndef GAMESTUDIO_H
#define GAMESTUDIO_H
#include <iostream>
#include <string>

#include "subject.h"
#include "piece.h"
#include "player.h"


class GameBoard;

class GameStudio : public Subject {
  int whiteWins, blackWins;
  std::ostream &out = std::cout;
  std::istream &in = std::cin;
  Player * white;
  Player * black;
  GameBoard *Board;

 public:
  GameStudio();

  GameBoard *getBoard();
  void setBoard(GameBoard * Board);

  void setWhite(Player * player);
  void setBlack(Player * player);
  Player *getWhite();
  Player *getBlack();
  int getWhiteWins();
  int getBlackWins();

  void movePiece(int startRow, int startCol, int endRow, int endCol, std::string color);
  void setup();

  void render();
  char getState(int row, int col) const override;
  ~GameStudio();
};

#endif
