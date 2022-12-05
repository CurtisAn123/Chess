#include "empty.h"

Empty::Empty(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Empty::move(int r, int c) { return false; }

Empty::~Empty() {}
