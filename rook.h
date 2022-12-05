#ifndef _ROOK_H_
#define _ROOK_H_

#include "piece.h"

class Rook : public Piece {
  
public:
  Rook(std::string color, char type, int row, int col);
  void move(int c, int r);
};

#endif
