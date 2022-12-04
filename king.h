#ifndef _KING_H
#define _KING_H_

#include "piece.h"

class King : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
