#include "gameboard.h"
#include "piece.h"
#include "empty.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

GameBoard::GameBoard() {
  // allocating the memory for the 2d array of pointers
  pieces = new Piece**[8]; // allocates rows
  for (int i = 0; i < 8; ++i) {
    pieces[i] = new Piece*[8];
  } //allocates cols

  // hardcode this for a default setup

  // black pieces
  pieces[0][0] = new Rook("black", 'r', 0, 0);
  pieces[0][1] = new Knight("black", 'n', 0, 1);
  pieces[0][2] = new Bishop("black", 'b', 0, 2);
  pieces[0][3] = new Queen("black", 'q', 0, 3);
  pieces[0][4] = new King("black", 'k', 0, 4);
  pieces[0][5] = new Bishop("black", 'b', 0, 5);
  pieces[0][6] = new Knight("black", 'n', 0, 6);
  pieces[0][7] = new Rook("black", 'r', 0, 7);

  for (int i = 0; i < 8; ++i) {
    pieces[1][i] = new Pawn("black", 'p', 0, i);
  }

  for (int i = 2; i < 6; ++i) {
    for (int j = 0; j < 8; ++j) {
      pieces[i][j] = new Empty("", ' ', i, j);
    }
  }

  for (int i = 0; i < 8; ++i) {
    pieces[6][i] = new Pawn("white", 'p', 6, i);
  }

  pieces[7][0] = new Rook("white", 'r', 7, 0);
  pieces[7][1] = new Knight("white", 'n', 7, 1);
  pieces[7][2] = new Bishop("white", 'b', 7, 2);
  pieces[7][3] = new Queen("white", 'q', 7, 3);
  pieces[7][4] = new King("white", 'k', 7, 4);
  pieces[7][5] = new Bishop("white", 'b', 7, 5);
  pieces[7][6] = new Knight("white", 'n', 7, 6);
  pieces[7][7] = new Rook("white", 'r', 7, 7);
  
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
