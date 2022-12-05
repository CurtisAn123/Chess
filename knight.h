#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"

class Knight : public Piece {
  
public:
  Knight(std::string color, char type, int row, int col);
  void move(int c, int r);
};

#endif
