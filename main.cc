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
#include "checkmate.h"

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
      
      // setting appropriate players up
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
      if (s.getBoard() == nullptr) {
        GameBoard *board = new GameBoard();
        s.setBoard(board);
      }
    }
    else if (command == "setup") {
      // codes a new Board constructor with a parameter that tells it to enter setup mode

      GameBoard *board = new GameBoard(true);
      s.setBoard(board);
      s.setup();
    }
    else if (command == "move") {
      if (s.getBoard() == nullptr) {
        std::cout << "Please create a game first" << std::endl;
        continue;
      }
      if (s.getWhite() == nullptr) {
        std::cout << "Please create a game first" << std::endl;
        continue;
      }
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
        std::cout << "Invalid Move: " << e.getMsg() << std::endl;
      } catch (Checkmate c) {
        std::cout << "Checkmate! " <<  c.getColor() << " wins!" << std::endl;
      }
    }
    else if (command == "addtext") {
      Text * text = new Text{&s};
      observers.push_back(text);
      s.attach(observers.back());
    }
    else if (command == "addgraphics") {
      // implement graphics here
      std::cout << "Graphics Window" << std::endl;
    }
    else {
      std::cout << "Invalid Command" << std::endl;
    }
  }

  std::cout << "Final Score:" << std::endl;
  std::cout << "White: " << s.getWhiteWins() << std::endl;
  std::cout << "Black: " << s.getBlackWins() << std::endl;
  
  for (auto & ob: observers) {
    delete ob;
  } // delete all observers
  
}
