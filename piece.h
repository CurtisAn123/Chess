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
  bool move(int c, int r);
  char getType () const;
  void getColour() const;
  void print();
  ~Piece();
};

#endif
  

