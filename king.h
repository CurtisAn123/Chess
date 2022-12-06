#ifndef _KING_H_
#define _KING_H_

#include "piece.h"

class King : public Piece {
  
public:
  King(std::string color, char type, int row, int col);
  bool move(int c, int r, Piece*** pieces) override;
  int getRow();
  int getCol();
  ~King();
};

#endif
