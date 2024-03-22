#include "gtest/gtest.h"

#include "Board.h"

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
  Board b(rows,cols);

  b.display();

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      b.setElement(i,j,1);
      EXPECT_EQ(b.getElement(i,j), 1);
    }
  }

  b.display();
}
