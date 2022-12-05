#include "gamestudio.h"
#include "gameboard.h"
#include "piece.h"
#include "invalidmove.h"

void GameStudio::movePiece(int startRow, int startCol, int endRow, int endCol, std::string color) {
  /*
  if (startRow > 7 || startRow < 0 || startCol > 7 || startCol < 0 || endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0) {
    throw InvalidMove{};
  }
  */
  Board->move(startRow, startCol, endRow, endCol, color);
}

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
