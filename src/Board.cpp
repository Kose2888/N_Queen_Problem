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
  std::cout << "  ";
  for(int i = 0; i < (cols); i++) {
    std::cout << std::setfill(' ');
    std::cout << std::right << std::setw(3);
    std::cout << i;
  }
  std::cout << "\n  " <<
    std::setfill('-') << std::right << std::setw(cols*3+1);

  int j = 0;
  for(int i = 0; i < (rows * cols); i++) {
    if((i % cols) == 0) {
      if(j >= 10)
        std::cout << "\n" << j << "| ";
      else
        std::cout << "\n" << j << " | ";
      j++;
    }

    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(2);

    if(element[i] == 1)
      std::cout << "Q" << " ";
    else
      std::cout << "." << " ";

  }
  std::cout << "\n" << std::endl;
}

void Board::setElement(int r, int c, int n) {
  if(r <= rows && c <= cols && r >= 0 && c >= 0 && (n == 1 || n == 0))
    element[rows*r + c] = n;
  else
    std::cout << "Error: Invalid set, not within board" << std::endl;
}

int Board::getElement(int r, int c) const {
  return element[rows*r + c];
}
