#include "empty.h"

Empty::Empty(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Empty::move(int r, int c, Piece*** pieces) { 
  std::cout << "This spot is empty" << std::endl;
  return false; 
  }

Empty::~Empty() {}
