#include "pawn.h"

Pawn::Pawn(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Pawn::move(int r, int c) {

}

Pawn::~Pawn() {}
