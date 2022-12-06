#include "bishop.h"

Bishop::Bishop(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Bishop::move(int r, int c, Piece*** pieces) {
  if (abs(r - row) != abs(c - col)) {
    return false;
    } else if (r > row && c > col){ //moving diagonally down right
      for (int i = row, j = col; i < r, j < c; i++, j++) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    } else if (r < row && c > col){ //moving diagonally up right
      for (int i = row, j = col; i > r, j < c; i--, j++) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    } else if (r > row && c < col){ //moving diagonally down left
      for (int i = row, j = col; i < r, j > c; i++, j--) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    } else if (r < row && c < col){ //moving diagonally up left
      for (int i = row, j = col; i > r, j > c; i--, j--) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    }
}

Bishop::~Bishop() {}
