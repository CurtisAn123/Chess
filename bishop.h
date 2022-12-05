#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"

class Bishop : public Piece {
  
public:
  Bishop(std::string color, char type, int row, int col);
  bool move(int r, int c) override;
  ~Bishop();
};

#endif
