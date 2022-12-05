#include "gamestudio.h"
#include "gameboard.h"
#include "piece.h"

char GameStudio::getState(int row, int col) const {
  Piece *piece = Board->getPiece(row, col);
  char c = piece->getType();
  if (c == ' ') {
    if ((row+col) % 2 == 0) {
      return c;
    }
    return '_';
  } // return for empty spaces
  if (piece->getColor() == "white") {
    return c - 32; // capitalizes text
  }
  return c;
}

void GameStudio::render() {
  notifyObservers();
}

GameStudio::~GameStudio() { delete Board; }
