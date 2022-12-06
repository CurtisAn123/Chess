#ifndef PLAYER_H
#define PLAYER_H

class Player {
  char type;
public:
  Player();
  explicit Player(char type);
  char getType();
  virtual ~Player() = default;
};

#endif
