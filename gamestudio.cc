#include "gamestudio.h"
#include "gameboard.h"
#include "piece.h"
#include "invalidmove.h"

GameStudio::GameStudio(): whiteWins{0}, blackWins{0}, white{nullptr}, black{nullptr}, Board{nullptr} {}

GameBoard *&GameStudio::getBoard() { return Board; }
void GameStudio::setBoard(GameBoard * Board) {
  if (this->Board) {
    delete this->Board;
  }
  this->Board = Board; }

void GameStudio::setWhite(Player * player) {
  if (white) {
    delete white;
  }
  white = player;
}
void GameStudio::setBlack(Player * player) {
  if (black) {
    delete black;
  }
  black = player;
}

Player *&GameStudio::getWhite() { return white; }
Player *&GameStudio::getBlack() { return black; }

void GameStudio::movePiece(int startRow, int startCol, int endRow, int endCol, std::string color) {
  if (startRow > 7 || startRow < 0 || startCol > 7 || startCol < 0 || endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0) {
    out << "out of range";
    throw InvalidMove{};
  }
  Board->move(startRow, startCol, endRow, endCol, color);
  render();

  // code checkmate and stalemate HERE. Throw exceptions for each
  // catch in main. Checkmate exception should have a string on who wins

  if (Board->check("white")) {
    out << "White king is in check." << std::endl;
  }
  if (Board->check("black")) {
    out << "Black king is in check." << std::endl;
  }
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

GameStudio::~GameStudio() {
  delete Board;
  delete white;
  delete black;
}
