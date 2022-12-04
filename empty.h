#ifndef _EMPTY_H_
#define _EMPTY_H_

#include "piece.h"

class Empty : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
