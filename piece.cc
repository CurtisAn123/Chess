#include "piece.h"

Piece::Piece(std::string color, char type, int row, int col):
  color{color}, type{type}, row{row}, col{col} {}

char Piece::getType() const {
  return type;
}

Piece::~Piece() {}
