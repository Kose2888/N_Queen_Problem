#include "Board.h"

Board::Board(int r, int c) {
  rows = r;
  cols = c;
  int size = r*c;

  element = new int[size];
  for(int i = 0; i < size; i++) {
   element[i] = 0;
  }

}

Board::~Board() {
  delete [] element;
}

void Board::display() {
  for(int i = 0; i < (rows * cols); i++) {
    if((i % cols) == 0)
      std::cout << "\n";

    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(2);

    if(element[i] == 1)
      std::cout << "Q" << " ";
    else
      std::cout << "." << " ";

  }
}

int* Board::getElement() {
  return element;
}
