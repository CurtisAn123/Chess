#include <iostream>
#include <string>
#include <vector>

#include "observer.h"
#include "text.h"
#include "subject.h"

#include "gameboard.h"
#include "gamestudio.h"

#include "piece.h"

#include "invalidmove.h"

int main() {
  
  std::vector<Observer*> observers;

  GameBoard *board = new GameBoard();

  GameStudio s{board};

  std::string command;
  bool whiteToPlay = true;

  while (std::cin >> command) {
    if (command == "render") {
      // will remove this command later, here for debugging
      // prints current board state
      s.render();
    }
    else if (command == "move") {
      try {
        char start, end;
        int startRow, startCol, endRow, endCol;
        std::cin >> start >> startRow >> end >> endRow;

        // fixing coordinates as a1 is at (0,0)
        startCol = start - 97;
        endCol = end - 97;
        startRow = 8 - startRow;
        endRow = 8 - endRow;
        std::cout << startRow << startCol << endRow << endCol << std::endl;
        if (whiteToPlay) {
          s.movePiece(startRow, startCol, endRow, endCol, "white");
        } else {
          s.movePiece(startRow, startCol, endRow, endCol, "black");
        }
        s.render();
        whiteToPlay = !whiteToPlay;
      } catch (InvalidMove e) {
        std::cout << "Invalid Move" << std::endl;
      }
    }
    else if (command == "addtext") {
      Text * text = new Text{&s};
      observers.push_back(text);
      s.attach(observers.back());
    }
  }
  
  for (auto & ob: observers) {
    delete ob;
  } // delete all observers
  
}
