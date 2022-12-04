#ifndef TEXT_H
#define TEXT_H

#include "observer.h"
#include "gamestudio.h"
#include <iostream>

class Text: public Observer {
  GameStudio * studio;
  std::ostream &out = std::cout;

  public:
    explicit Text(GameStudio * studio);
    ~Text();
    void notify() override;
};

#endif
