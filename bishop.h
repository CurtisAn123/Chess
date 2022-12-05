#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"

class Bishop : public Piece {
  
public:
  Bishop(std::string color, char type, int row, int col);
  void move(int c, int r);
  
};

#endif
