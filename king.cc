#include "king.h"

King::King(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool King::move(int r, int c) {

}

int King::getRow() { return row; }

int King::getCol() { return col; }

King::~King() {}
