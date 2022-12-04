#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"

class Knight : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
