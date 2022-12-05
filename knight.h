#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"

class Knight : public Piece {
  
public:
  Knight(std::string color, char type, int row, int col);
  bool move(int r, int c) override;
};

#endif
