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

    void setElement(int r, int c, int n);

    int getElement(int r, int c) const;


};


#endif
