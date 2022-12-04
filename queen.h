#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "piece.h"

class Queen : public Piece {
  
public:
  void move(int c, int r);
  void print();
  
};

#endif
