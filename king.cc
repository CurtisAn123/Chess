#include "king.h"

King::King(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool King::move(int r, int c, Piece*** pieces) {
  if ((abs(r - row) != 1 && abs(r - row) != 0) || (abs(c - col) != 0 && abs(c - col) != 1)) {
        return false;
      }
}

int King::getRow() { return row; }

int King::getCol() { return col; }

King::~King() {}
