#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include "piece.h"

class GameBoard {
  std::ostream &out = std::cout;

  Piece *** pieces;
  Piece * whiteKing;
  Piece * blackKing;

  bool checkmate();
  bool check();
  bool stalemate();

 public:
  GameBoard();
  bool validMove(int startRow, int startCol, int endRow, int endCol);
  bool legalBoard();
  void resetBoard();

  Piece *getPiece(int row, int col);
  void setPiece(Piece* p, int c, int r);

  ~GameBoard();

};

#endif