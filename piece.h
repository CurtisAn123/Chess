#ifndef _PIECE_H_
#define _PIECE_H_

class Piece {
  Color color;
  std::string type;
  int row, col;
  
public:
  bool move(int c, int r);
  std::string getType () const;
  void getColour() const;
  void print();
};

#endif
  

