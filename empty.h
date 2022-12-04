#ifndef _EMPTY_H_
#define _EMPTY_H_

#include "piece.h"

class Empty : public Piece {
  
public:
  Empty(std::string color, char type, int row, int col);
  void move(int c, int r);
  void print();
  
};

#endif
