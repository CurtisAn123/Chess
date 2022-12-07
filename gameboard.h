#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <string>
#include "piece.h"
#include "king.h"

class GameBoard {

  std::ostream &out = std::cout;

  Piece *** pieces;
  Piece * whiteKing;
  Piece * blackKing;

  bool stalemate();
  bool pawnPromotion(int r, int c, std::string color);

  bool verticalCheck(int r, int c, std::string color);
  bool diagonalCheck(int r, int c, std::string color);
  bool knightCheck(int r, int c, std::string color);
  bool pawnCheck(int r, int c, std::string color);
  bool kingCheck(int r, int c, std::string color);

 public:
  GameBoard();
  GameBoard(bool setup);
  void move(int startRow, int startCol, int endRow, int endCol, std::string color);

  bool check(std::string color);
  bool check(std::string color, int r, int c);
  bool checkmate(std::string color);
  
  bool legalBoard(); // checks if the board is in a legal state

  Piece *getPiece(int row, int col);
  void setPiece(Piece *p, int r, int c);

  ~GameBoard();
};

#endif
