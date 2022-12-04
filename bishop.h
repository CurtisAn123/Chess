#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"

class Bishop : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
