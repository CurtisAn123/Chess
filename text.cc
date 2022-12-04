#include "text.h"

Text::Text(GameStudio * studio) : studio{studio} {}

Text::~Text() {}

void Text::notify() {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        out << studio->getState(i, j);
      }
      out << std::endl;
    }
}
