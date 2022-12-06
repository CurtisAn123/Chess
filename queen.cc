#include "queen.h"

Queen::Queen(std::string color, char type, int row, int col):
  Piece{color, type, row, col} {}

bool Queen::move(int r, int c, Piece*** pieces) {
  if ((abs(r - row) != abs(c - col)) && (r != row && c != col) && (abs(r - row) != abs(c - col))) {
        return false;
      } else if (r == row) { 
        if (c > col) {  // moving to the right
          for (int i = col + 1; i < c - 1; i++){
          if (pieces[row][i]->getType() != ' '){
            return false;
          }
        }
        } else if (col > c) {  // moving to the left
          for (int i = col - 1; i > c + 1; i--){
          if (pieces[row][i]->getType() != ' '){
            return false;
          }
        }
        }
      } else if (c == col) { // moving downwards
        if (r > row) {
          for (int i = row + 1; i < r - 1; i++){
          if (pieces[i][col]->getType() != ' '){
            return false;
          }
        }
        } else if (row > r) { // moving upwards
          for (int i = row - 1; i > r + 1; i--){
          if (pieces[i][col]->getType() != ' '){
            return false;
          }
        }
        }
      } else if (r > row && c > col){ //moving diagonally down right
      for (int i = row + 1, j = col + 1; i < r - 1 && j < c - 1; i++, j++) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    } else if (r < row && c > col){ //moving diagonally up right
      for (int i = row - 1, j = col + 1; i > r + 1 && j < c - 1; i--, j++) {
        if (pieces[i][j]->getType() != ' ') {
          std::cout << i << j << pieces[i][j]->getType() << std::endl;
          return false;
        }
      }
    } else if (r > row && c < col){ //moving diagonally down left
      for (int i = row + 1, j = col - 1; i < r - 1 && j > c + 1; i++, j--) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    } else if (r < row && c < col){ //moving diagonally up left
      for (int i = row - 1, j = col - 1; i > r + 1 && j > c + 1; i--, j--) {
        if (pieces[i][j]->getType() != ' ') {
          return false;
        }
      }
    }
    row = r;
    col = c;
    return true;
}

Queen::~Queen() {}
