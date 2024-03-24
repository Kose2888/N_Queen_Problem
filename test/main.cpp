#include "gtest/gtest.h"

#include "Board.h"
#include "Game.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class Test : public testing::Test {
  protected:

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(Test, boardContructorTest) {
  int rows = 5;
  int cols = 5;
  Board *b = new Board(rows,cols);

  b->display();

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      b->setElement(i,j,1);
      EXPECT_EQ(b->getElement(i,j), 1);
      b->setElement(i,j,0);
    }
  }

  b->display();

  delete b;
}

TEST_F(Test, gameConstructorTest) {
  int input = 4;
  Game *g = new Game(input);

  g->getBoard()->display();

  delete g;
}

TEST_F(Test, gameIsSafe) {
  int input = 4;
  Game *g = new Game(input);

  g->getBoard()->setElement(2,3,1);
  g->getBoard()->display();

  // Test is safe left of row
  g->getBoard()->setElement(2,2,1);
  g->getBoard()->display();
  EXPECT_EQ(g->isSafe(2,3), false);
  g->getBoard()->setElement(2,2,0);

  // Test is safe for upper diagonal
  g->getBoard()->setElement(1,2,1);
  g->getBoard()->display();
  EXPECT_EQ(g->isSafe(2,3), false);
  g->getBoard()->setElement(1,2,0);

  // Test is safe for lower diagonal
  g->getBoard()->setElement(2,3,0);
  g->getBoard()->setElement(1,3,1);

  g->getBoard()->setElement(3,1,1);
  g->getBoard()->display();
  EXPECT_EQ(g->isSafe(1,3), false);

  // Checking if it glitches in corner
  g->getBoard()->setElement(1,3,0);
  g->getBoard()->setElement(3,1,0);
  g->getBoard()->setElement(3,3,0);
  EXPECT_EQ(g->isSafe(3,3), true);
  g->getBoard()->display();
  delete g;
}

TEST_F(Test, gameSolveNQueen) {
  int input = 4;
  Game *g = new Game(input);

  g->solveNQueen(0);
  g->getBoard()->display();


  delete g;
}
/*
TEST_F(Test, gameStartGame) {
  int input = 0;

  std::cout << "Enter a number: ";
  std::cin >> input;

  Game *g = new Game(input);

  g->startGame();

  delete g;
}
*/
