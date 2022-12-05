#include "king.h"

King::King(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

int King::getRow() { return row; }

int King::getCol() { return col; }
