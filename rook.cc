#include "rook.h"

Rook::Rook(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Rook::move(int r, int c, Piece*** pieces) {
  if (r != row && c != col) {
        return false;
      } else if (r == row) {
        if (c > col) { // moving to the right
          for (int i = col; i < c; i++){
          if (pieces[row][i]->getType() != ' '){
            return false;
          }
        }
        } else if (col > c) { // moving to the left
          for (int i = col; i > c; i--){
          if (pieces[row][i]->getType() != ' '){
            return false;
          }
        }
        }
      } else if (c == col) {
        if (r > row) { // moving downwards
          for (int i = row; i < r; i++){
          if (pieces[i][col]->getType() != ' '){
            return false;
          }
        }
        } else if (row > r) { // moving upwards
          for (int i = row; i > r; i--){
          if (pieces[i][col]->getType() != ' '){
            return false;
          }
        }
        }
      }
}

Rook::~Rook() {}
