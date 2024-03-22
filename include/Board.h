#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <iomanip>


class Board {
  private:
    int rows = 0;
    int cols = 0;
    int *element;

  public:

    Board(int r, int c);

    ~Board();

    void display();

    int* getElement();

};


#endif
