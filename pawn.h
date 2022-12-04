#ifndef _PAWN_H_
#define _PAWN_H_

#include "piece.h"

class Pawn : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
