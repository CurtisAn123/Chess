#include "gamestudio.h"
#include "gameboard.h"
#include "piece.h"

char GameStudio::getState(int row, int col) const {
  Piece *piece = Board->getPiece(row, col);
  if (piece->getColor() == "white") {
    return piece->getType() - 32;
  }
  return piece->getType();
}

void GameStudio::render() {
  notifyObservers();
}

GameStudio::~GameStudio() { delete Board; }
