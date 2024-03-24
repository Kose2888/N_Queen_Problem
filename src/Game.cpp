#include "Game.h"

Game::Game(int n) {
  input = n;
  b = new Board(n, n);
}

Game::~Game() {
  delete b;
}

bool Game::isSafe(int r, int c) {
  int i,j;
  // Check left of this row
  for(i = 0; i < c; i++) {
    if(b->getElement(r,i)) { // A queen is stored as 1
        return false;
    }
  }

  // Check upper diagonal on left side
  for(i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
    if(b->getElement(i,j))
      return false;
  }

  // Check lower diagonal on left side
  for(i = r+1, j = c-1; j >= 0 && i < input; i++, j--) {
    if(b->getElement(i,j))
      return false;
  }

  return true;
}

bool Game::solveNQueen(int c) {
  //base case: true if all queens are placed
  if(c >= input)
    return true;

  for(int i = 0; i < input; i++) {
    if(isSafe(i, c)) {
      b->setElement(i,c,1);

      if(solveNQueen(c + 1))
        return true;

      // Backtrack
      b->setElement(i,c,0);
    }
  }
  return false;
}

void Game::startGame() {
  if(solveNQueen(0) == false) {
    std::cout << "Solution does not exist" << std::endl;
  }
  b->display();
}
