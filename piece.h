#ifndef _PIECE_H_
#define _PIECE_H_

#include <string>
#include <iostream>

class Piece {
protected:
  std::string color;
  char type;
  int row, col;
  
public:
  Piece(std::string color, char type, int row, int col);
  virtual bool move(int r, int c) = 0;
  char getType () const;
  std::string getColor() const;
  virtual ~Piece() = default;
};

#endif
  

