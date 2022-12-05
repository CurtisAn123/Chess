#ifndef _ROOK_H_
#define _ROOK_H_

#include "piece.h"

class Rook : public Piece {
  
public:
  Rook(std::string color, char type, int row, int col);
  bool move(int r, int c) override;
  ~Rook();
};

#endif
