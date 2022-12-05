#ifndef _PAWN_H_
#define _PAWN_H_

#include "piece.h"

class Pawn : public Piece {
  
public:
  Pawn(std::string color, char type, int row, int col);
  bool move(int r, int c) override;
  ~Pawn();
};

#endif
