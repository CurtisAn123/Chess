#include <iostream>
#include <string>
#include <vector>

#include "observer.h"
#include "text.h"
#include "subject.h"

#include "gameboard.h"
#include "gamestudio.h"

#include "piece.h"
#include "empty.h"

int main() {
  
  std::vector<Observer*> observers;

  GameBoard *board = new GameBoard();

  GameStudio s{board};

  std::string command;

  while (std::cin >> command) {
    if (command == "render") {
      s.render();
    }
    else if (command == "addtext") {
      Text * text = new Text{&s};
      observers.push_back(text);
      s.attach(observers.back());
    }
  }
  
  for (auto & ob: observers) {
    delete ob;
  }
  
}
