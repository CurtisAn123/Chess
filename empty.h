#ifndef _EMPTY_H_
#define _EMPTY_H_

#include "piece.h"

class Empty : public Piece {
  
public:
  Empty(std::string color, char type, int row, int col);
  bool move(int r, int c);
  ~Empty();
};

#endif
