#include "gamestudio.h"
#include "gameboard.h"
#include "piece.h"
#include "queen.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "empty.h"

#include "invalidmove.h"

GameStudio::GameStudio(): whiteWins{0}, blackWins{0}, white{nullptr}, black{nullptr}, Board{nullptr} {}

GameBoard *GameStudio::getBoard() { return Board; }

void GameStudio::setBoard(GameBoard * Board) {
  if (this->Board) {
    delete this->Board;
  }
  this->Board = Board;
}

void GameStudio::setup() {
  std::string command;
  while (in >> command) {
    if (command == "+") {
      char type, column;
      int row, col;
      std::cin >> type >> column >> row;
      col = column - 97;
      row = 8 - row;
      Piece * p;
      if (type == 'K') {
        p = new King("white", 'k', row, col);
      } else if (type == 'k') {
        p = new King("black", 'k', row, col);
      } else if (type == 'Q') {
        p = new Queen("white", 'q', row, col);
      } else if (type == 'q') {
        p = new Queen("black", 'q', row, col);
      } else if (type == 'P') {
        p = new Pawn("white", 'p', row, col);
      } else if (type == 'p') {
        p = new Pawn("black", 'p', row, col);
      } else if (type == 'B') {
        p = new Bishop("white", 'b', row, col);
      } else if (type == 'b') {
        p = new Bishop("black", 'b', row, col);
      } else if (type == 'N') {
        p = new Knight("white", 'n', row, col);
      } else if (type == 'n') {
        p = new Knight("black", 'n', row, col);
      } else if (type == 'R') {
        p = new Rook("white", 'r', row, col);
      } else if (type == 'r') {
        p = new Rook("black", 'r', row, col);
      }
      Board->setPiece(p, row, col);
      render();
    } else if (command == "-") {
      char column;
      int row, col;
      in >> column >> row;
      col = column - 97;
      row = 8 - row;
      Piece * p = new Empty("", ' ', row, col);
      Board->setPiece(p, row, col);
      render();
    } else if (command == "done") {
      if (Board->legalBoard()) {
        return;
      } else {
        out << "Board is not in a legal state" << std::endl;
      }
    }
  }
}

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

Player *GameStudio::getWhite() { return white; }
Player *GameStudio::getBlack() { return black; }

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
