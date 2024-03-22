#include "Board.h"

Board::Board() {
}

Board::~Board() {
}

Board::Board(int r, int c) {
  row = r;
  col = c;
}

void Board::display() {
  for(int i = 0; i < row; i++) {
    std::cout << std::endl;
    for(int j = 0; i < col; j++) {
      std::cout << board[i][j] << " ";
    }
  }
}
