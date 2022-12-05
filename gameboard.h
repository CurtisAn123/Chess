#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include "piece.h"
#include "king.h"

class GameBoard {
  friend class GameStudio;

  std::ostream &out = std::cout;

  Piece *** pieces;
  King * whiteKing;
  King * blackKing;

  bool checkmate();
  bool check(std::string color);
  bool stalemate();

 public:
  GameBoard();
  void move(int startRow, int startCol, int endRow, int endCol, std::string color);
  bool legalBoard();
  void resetBoard();

  Piece *getPiece(int row, int col);
  void setPiece(Piece* p, int c, int r);

  ~GameBoard();
};

#endif
