#include "gameboard.h"
#include "piece.h"
#include "empty.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "invalidmove.h"

GameBoard::GameBoard() {
  // allocating the memory for the 2d array of pointers
  pieces = new Piece**[8]; // allocates rows
  for (int i = 0; i < 8; ++i) {
    pieces[i] = new Piece*[8];
  } //allocates cols

  // hardcode this for a default setup
  whiteKing = new King("white", 'k', 7, 4);
  blackKing = new King("black", 'k', 0, 4);;

  // black pieces
  pieces[0][0] = new Rook("black", 'r', 0, 0);
  pieces[0][1] = new Knight("black", 'n', 0, 1);
  pieces[0][2] = new Bishop("black", 'b', 0, 2);
  pieces[0][3] = new Queen("black", 'q', 0, 3);
  pieces[0][4] = blackKing;
  pieces[0][5] = new Bishop("black", 'b', 0, 5);
  pieces[0][6] = new Knight("black", 'n', 0, 6);
  pieces[0][7] = new Rook("black", 'r', 0, 7);

  for (int i = 0; i < 8; ++i) {
    pieces[1][i] = new Pawn("black", 'p', 0, i);
  }

  // empty spaces
  for (int i = 2; i < 6; ++i) {
    for (int j = 0; j < 8; ++j) {
      pieces[i][j] = new Empty("", ' ', i, j);
    }
  }

  // white pieces
  for (int i = 0; i < 8; ++i) {
    pieces[6][i] = new Pawn("white", 'p', 6, i);
  }

  pieces[7][0] = new Rook("white", 'r', 7, 0);
  pieces[7][1] = new Knight("white", 'n', 7, 1);
  pieces[7][2] = new Bishop("white", 'b', 7, 2);
  pieces[7][3] = new Queen("white", 'q', 7, 3);
  pieces[7][4] = whiteKing;
  pieces[7][5] = new Bishop("white", 'b', 7, 5);
  pieces[7][6] = new Knight("white", 'n', 7, 6);
  pieces[7][7] = new Rook("white", 'r', 7, 7);
}

void GameBoard::move(int startRow, int startCol, int endRow, int endCol, std::string color) {
  Piece * p = pieces[startRow][startCol];
  Piece * endp = pieces[endRow][endCol];
  if (p->getColor() != color) {
    throw InvalidMove{};
  } 
  if (endp->getColor() == color) {
    std::cout <<"There's already a piece there" << std::endl;
    throw InvalidMove{};
  }

//checks for valid moves for every type of piece
  if (p->getType() == 'p') {  //checks for valid pawn move
    if (color == "white") {
      if (startRow == 6 && endCol - startCol == 0 && startRow - endRow != 1 && startRow - endRow != 2){
        throw InvalidMove{};
      } else if (startRow != 6 && endCol - startCol == 0 && startRow - endRow != 1) {
        throw InvalidMove{};
      } else if (abs(endCol - startCol) == 1 && startRow - endRow == 1 && endp->getColor() != "black") { // checks for valid pawn capture
        throw InvalidMove{};
      } else if (startRow - endRow == 2 && pieces[startRow-1][startCol]->getType() != ' '){ // checks for pieces in path of pawn
        throw InvalidMove{};
      }
    } else if (color == "black"){
      if (startRow == 1 && endCol - startCol == 0 && endRow - startRow != 1 && endRow - startRow != 2){
        throw InvalidMove{};
      } else if (startRow != 1 && endCol - startCol == 0 && endRow - startRow != 1) {
        throw InvalidMove{};
      } else if (abs(endCol - startCol) == 1 && endRow - startRow == 1 && endp->getColor() != "white") { // checks for valid pawn capture
        throw InvalidMove{};
      } else if (endRow - startRow == 2 && pieces[endRow-1][startCol]->getType() != ' '){ // checks for pieces in path of pawn
        throw InvalidMove{};
      }
    }
  }

  if (p->getType() == 'r') { //checks for valid rook move
      if (endRow != startRow && endCol != startCol) {
        throw InvalidMove{};
      } else if (endRow == startRow) {
        if (endCol > startCol) {
          for (int i = startCol; i < endCol; i++){
          if (pieces[startRow][i]->getType() != ' '){
            std::cout << "something is blockign the way" << std::endl;
            throw InvalidMove{};
          }
        }
        } else if (startCol > endCol) {
          for (int i = startCol; i > endCol; i--){
          if (pieces[startRow][i]->getType() != ' '){
            std::cout << "something is blockign the way" << std::endl;
            throw InvalidMove{};
          }
        }
        }
      } else if (endCol == startCol) {
        if (endRow > startRow) {
          for (int i = startRow; i < endRow; i++){
          if (pieces[i][startCol]->getType() != ' '){
            std::cout << "something is blockign the way" << std::endl;
            throw InvalidMove{};
          }
        }
        } else if (startRow > endRow) {
          std::cout << "got here" << std::endl;
          for (int i = startRow; i > endRow; i--){
          if (pieces[i][startCol]->getType() != ' '){
            std::cout << "something is blockign the way" << std::endl;
            throw InvalidMove{};
          }
        }
        }
      }
  }

  if (p->getType() == 'b') { //checks for valid bishop move
      if (abs(endRow - startRow) != abs(endCol - startCol)) {
        throw InvalidMove{};
      }
  }
  
  if (p->getType() == 'n') { //checks for valid knight move
      if ((abs(endRow - startRow) != 2 || abs(endCol - startCol) != 1) && (abs(endRow - startRow) != 1 || abs(endCol - startCol) != 2 )) {
        throw InvalidMove{};
      }
  }

  if (p->getType() == 'q') { //checks for valid queen move
      if ((abs(endRow - startRow) != abs(endCol - startCol)) && (endRow != startRow && endCol != startCol)) {
        throw InvalidMove{};
      }
  }

    if (p->getType() == 'k') { //checks for valid king move
      if ((abs(endRow - startRow) != 1 && abs(endRow - startRow) != 0) || (abs(endCol - endCol) != 0 && abs(endCol - endCol) != 1)) {
        throw InvalidMove{};
      }
  }

  pieces[startRow][startCol] = new Empty("", ' ', startRow, startCol);
  if (!legalBoard()) {
    throw InvalidMove{};
  } // checks if board is legal if piece has moved (original square is empty)

  /*
  if (!p->move(endRow, endCol)) {
    throw InvalidMove{};
  } // checks if p is able to move to the end square
  */

  delete pieces[endRow][endCol];
  pieces[endRow][endCol] = p;
}

bool GameBoard::verticalCheck(int r, int c, std::string color) {
  // checks for opposing pieces vertically that can deliver checks
  for (int i = r+1; i < 8; ++i) {
    if (pieces[i][c]->getColor() == color) {
      break;
    } else if (pieces[i][c]->getType() == 'r' || pieces[i][c]->getType() == 'q') {
      return true;
    }
  }
  for (int i = r-1; i >= 0; --i) {
    if (pieces[i][c]->getColor() == color) {
      break;
    } else if (pieces[i][c]->getType() == 'r' || pieces[i][c]->getType() == 'q') {
      return true;
    }
  }

  // checks for opposing pieces horizontally that can deliver checks
  for (int i = c+1; i < 8; ++i) {
    if (pieces[r][i]->getColor() == color) {
      break;
    } else if (pieces[r][i]->getType() == 'r' || pieces[r][i]->getType() == 'q') {
      return true;
    }
  }
  for (int i = c-1; i >= 0; --i) {
    if (pieces[r][i]->getColor() == color) {
      break;
    } else if (pieces[r][i]->getType() == 'r' || pieces[r][i]->getType() == 'q') {
      return true;
    }
  }
  
  return false;
}

bool GameBoard::diagonalCheck(int r, int c, std::string color) {
  // checks for diagonal checks
  int i = 1;
  while(r + i < 8 && c + i < 8) {
    if (pieces[r+i][c+i]->getColor() == color) {
      break;
    } else if (pieces[r+i][c+i]->getType() == 'b' || pieces[r+i][c+i]->getType() == 'q') {
      return true;
    }
    ++i;
  }
  i = 1;
  while(r - i >= 0 && c - i >= 0) {
    if (pieces[r-i][c-i]->getColor() == color) {
      break;
    } else if (pieces[r-i][c-i]->getType() == 'b' || pieces[r-i][c-i]->getType() == 'q') {
      return true;
    }
    ++i;
  }
  i = 1;
  while(r + i < 8 && c - i >= 0) {
    if (pieces[r+i][c-i]->getColor() == color) {
      break;
    } else if (pieces[r+i][c-i]->getType() == 'b' || pieces[r+i][c-i]->getType() == 'q') {
      return true;
    }
    ++i;
  }
  i = 1;
  while(r - i >= 0 && c + i < 8) {
    if (pieces[r-i][c+i]->getColor() == color) {
      break;
    } else if (pieces[r-i][c+i]->getType() == 'b' || pieces[r-i][c+i]->getType() == 'q') {
      return true;
    }
    ++i;
  }
  
  return false;
}

bool GameBoard::knightCheck(int r, int c, std::string color) {
  int kr, kc; // knight row, knight col
  // first 4 checks (r + 2)(c + 1)
  kr = r + 2;
  kc = c + 1;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r - 2;
  kc = c - 1;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r + 2;
  kc = c - 1;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r - 2;
  kc = c + 1;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }

  // next 4 checks (r + 1)(c + 2)
  kr = r + 1;
  kc = c + 2;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r - 1;
  kc = c - 2;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r + 1;
  kc = c - 2;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }
  kr = r - 1;
  kc = c + 2;
  if (kr < 8 && kr >= 0 && kc < 8 && kc >= 0) {
    if (pieces[kr][kc]->getColor() != color && pieces[kr][kc]->getType() == 'n') {
      return true;
    }
  }

  return false;
}

bool GameBoard::pawnCheck(int r, int c, std::string color) {
  int pr, pc; // pawn row, pawn col
  if (color == "white") {
    pr = r - 1;
    pc = c + 1;
    if (pr >= 0 && pc < 8) {
      if (pieces[pr][pc]->getColor() != color && pieces[pr][pc]->getType() == 'p') {
        return true;
      }
    }
    pc = c - 1;
    if (pr >= 0 && pc >= 0) {
      if (pieces[pr][pc]->getColor() != color && pieces[pr][pc]->getType() == 'p') {
        return true;
      }
    }
  } else {
    pr = r + 1;
    pc = c + 1;
    if (pr < 8 && pc < 8) {
      if (pieces[pr][pc]->getColor() != color && pieces[pr][pc]->getType() == 'p') {
        return true;
      }
    }
    pc = c - 1;
    if (pr < 8 && pc >= 0) {
      if (pieces[pr][pc]->getColor() != color && pieces[pr][pc]->getType() == 'p') {
        return true;
      }
    }
  }
  return false;
}

bool GameBoard::check(std::string color) {
  // returns true if color's king is in check
  int r, c;
  if (color == "white") {
    r = whiteKing->getRow();
    c = whiteKing->getCol();
  } else {
    r = blackKing->getRow();
    c = blackKing->getCol();
  }

  return verticalCheck(r, c, color) || diagonalCheck(r, c, color) || knightCheck(r, c, color) || pawnCheck(r, c, color);
}

bool GameBoard::legalBoard() {
  return true;
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
