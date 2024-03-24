#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Board.h"

class Game {
  private:
    Board *b;
    int input = 0;

  public:
    Game(int input);

    ~Game();

    Board* getBoard() {return b;}

    bool isSafe(int r, int c);
};


#endif
