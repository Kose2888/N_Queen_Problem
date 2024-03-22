#ifndef BOARD_H
#define BOARD_H

#include <iostream>


class Board {
  private:
    int row = 0;
    int col = 0;
    int board[0][0];

  public:

    Board();

    ~Board();

    Board(int r, int c);

    void display();

};


#endif
