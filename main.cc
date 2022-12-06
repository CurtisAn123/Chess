#include <iostream>
#include <string>
#include <vector>

#include "observer.h"
#include "text.h"
#include "subject.h"

#include "gameboard.h"
#include "gamestudio.h"

#include "human.h"
#include "computer.h"

#include "piece.h"

#include "invalidmove.h"

int main() {
  
  std::vector<Observer*> observers;

  GameStudio s{};

  std::string command;
  bool whiteToPlay = true;

  while (std::cin >> command) {
    if (command == "render") {
      // will remove this command later, here for debugging
      // prints current board state
      s.render();
    }
    else if (command == "game") {
      std::string white, black;
      std::cin >> white >> black;
      
      // setting appropriate players
      if (white == "human") {
        s.setWhite(new Human('h'));
      } else if (white == "computer") {
        s.setWhite(new Computer('c'));
      } else {
        std::cout << "Please specify human or computer" << std::endl;
        continue;
      }

      if (black == "human") {
        s.setBlack(new Human('h'));
      } else if (black == "computer") {
        s.setBlack(new Computer('c'));
      } else {
        std::cout << "Please specify human or computer" << std::endl;
        continue;
      }
      GameBoard *board = new GameBoard();
      s.setBoard(board);
    }
    else if (command == "setup") {
      // use getPiece and setPiece
    }
    else if (command == "move") {
      try {
        // checks if it is a human turn to play
        if ((whiteToPlay && s.getWhite()->getType() == 'h') || (!whiteToPlay && s.getBlack()->getType() == 'h')) {
          char start, end;
          int startRow, startCol, endRow, endCol;
          std::cin >> start >> startRow >> end >> endRow;

          // fixing coordinates as a1 is at (0,0)
          // converts characters to cols
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
        } else {
          // implement computer move here
          // have player->playBestMove() find the best move then call the move function itself
          std::cout << "Computer turn to play" << std::endl;
        }
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
