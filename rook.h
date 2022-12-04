#ifndef _ROOK_H_
#define _ROOK_H_

#include "piece.h"

class Rook : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
