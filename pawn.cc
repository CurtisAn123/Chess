#include "pawn.h"

Pawn::Pawn(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Pawn::move(int r, int c, Piece*** pieces) {
   if (color == "white") {
      if (row == 6 && c - col == 0 && row - r != 1 && row - r != 2){
        return false;
      } else if (row != 6 && c - col == 0 && row - r != 1) {
        return false;
      } else if (abs(c - col) == 1 && row - r == 1 && pieces[r][c]->getColor() != "black") { // checks for valid pawn capture
        return false;
      } else if (row - r == 2 && pieces[row-1][col]->getType() != ' '){ // checks for pieces in path of pawn
        return false;
      }
    } else if (color == "black"){
      if (row == 1 && c - col == 0 && r - row != 1 && r - row != 2){
        return false;
      } else if (row != 1 && c - col == 0 && r - row != 1) {
        return false;
      } else if (abs(c - col) == 1 && r - row == 1 && pieces[r][c]->getColor() != "white") { // checks for valid pawn capture
        return false;
      } else if (r - row == 2 && pieces[r-1][col]->getType() != ' '){ // checks for pieces in path of pawn
        return false;
      }
    }
}

Pawn::~Pawn() {}
