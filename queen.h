#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "piece.h"

class Queen : public Piece {
  
public:
  Queen(std::string color, char type, int row, int col);
  void move(int c, int r);
  
};

#endif
