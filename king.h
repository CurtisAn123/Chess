#ifndef _KING_H
#define _KING_H_

#include "piece.h"

class King : public Piece {
  
public:
  King(std::string color, char type, int row, int col);
  void move(int c, int r);
};

#endif
