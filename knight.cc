#include "knight.h"

Knight::Knight(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Knight::move(int r, int c, Piece*** pieces) {
  if ((abs(r - row) != 2 || abs(c - col) != 1) && (abs(r - row) != 1 || abs(c - col != 2 ))) {
        return false;
      }
}

Knight::~Knight() {}
