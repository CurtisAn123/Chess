#include "gameboard.h"
#include "piece.h"
#include "empty.h"

GameBoard::GameBoard() {
  // allocating the memory for the 2d array of pointers
  pieces = new Piece**[8]; // allocates rows
  for (int i = 0; i < 8; ++i) {
    pieces[i] = new Piece*[8];
  } //allocates cols

  // hardcode this for a default setup
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      pieces[i][j] = new Empty("white", 'e', i, j);
    }
  }
}

Piece * GameBoard::getPiece(int row, int col) {
  return pieces[row][col];
}

GameBoard::~GameBoard() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      delete pieces[i][j]; // delete each piece
    }
    delete[] pieces[i];
  }
  delete[] pieces;
}
