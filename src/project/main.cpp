#include <iostream>

#include "Game.h"

int main(int argc, char *argv []) {
  char answer;

  std::cout << "|--------------------N-Queens Problem--------------------|\n\n"
    << "The n-queens puzzle is the problem of placing n queens on an n x n\n"
    << "chessboard such that no two queens attack each other.\n" << std::endl;

  std::cout << "Enter a number no greater than ~25 (unless you have a\n"
    << "super computer), and the program will solve the puzzle." << std::endl;

  do{
    int input = 0;

    std::cout << "Enter: ";
    std::cin >> input;
    std::cout << std::endl;

    Game *g = new Game(input);

    g->startGame();

    delete g;

    std::cout << "Would you like to play again?(Y/N)";
    std::cin >> answer;
    std::cout << std::endl;

  }while(answer == 'Y' | answer == 'y');

}
