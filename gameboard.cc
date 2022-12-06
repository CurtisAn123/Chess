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

GameBoard::GameBoard(): whiteKing{new King("white", 'k', 7, 4)}, blackKing{new King("black", 'k', 0, 4)} {
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

GameBoard::GameBoard(bool setup): whiteKing{nullptr}, blackKing{nullptr} {
  // allocating the memory for the 2d array of pointers
  pieces = new Piece**[8]; // allocates rows
  for (int i = 0; i < 8; ++i) {
    pieces[i] = new Piece*[8];
  } //allocates cols

  // empty spaces
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      pieces[i][j] = new Empty("", ' ', i, j);
    }
  }
}

void GameBoard::move(int startRow, int startCol, int endRow, int endCol, std::string color) {
  Piece * p = pieces[startRow][startCol];
  Piece * endp = pieces[endRow][endCol];
  if (p->getColor() != color) {
    throw InvalidMove{};
  } 
  if (endp->getColor() == color) {
    throw InvalidMove{};
  }

  pieces[startRow][startCol] = new Empty("", ' ', startRow, startCol);
  if (!legalBoard()) {
    throw InvalidMove{};
  } // checks if board is legal if piece has moved (original square is empty)

    if (!p->move(endRow, endCol, pieces)) {
    throw InvalidMove{};
  } // checks if p is able to move to the end square
  
  delete pieces[endRow][endCol];
  pieces[endRow][endCol] = p;
}

bool GameBoard::pawnPromotion(int r, int c, std::string color){
  if (color == "white" && r == 0) {
    return true;
  } else if (color == "black" && r == 7) {
    return true;
  }
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
  // ensure both kings are NOT in check
  return !check("white") && !check("black");
}

Piece * GameBoard::getPiece(int row, int col) {
  return pieces[row][col];
}

void GameBoard::setPiece(Piece *p, int r, int c) {
  delete pieces[r][c];
  pieces[r][c] = p;
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
