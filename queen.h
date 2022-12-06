#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "piece.h"

class Queen : public Piece {
  
public:
  Queen(std::string color, char type, int row, int col);
  bool move(int r, int c, Piece*** pieces) override;
  ~Queen();
};

#endif
