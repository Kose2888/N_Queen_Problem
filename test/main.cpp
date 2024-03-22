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
  Board b(4,4);

  b.getElement()[1] = 1;
  b.getElement()[6] = 1;
  b.getElement()[15] = 1;
  b.display();
}
