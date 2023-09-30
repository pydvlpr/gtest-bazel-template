#include "../Func/func.h"
#include "gtest/gtest.h" // do not use a global installation of google test here but the local on installed via bazel

int sum(int,int);
int prod(int,int);

TEST(FunctionTests,AddTwoPositives){
    const int a = 2;
    const int b = 3;
    EXPECT_EQ(sum(a,b),5) << "The sum is not correct!";
}

TEST(FunctionTests,MultiplyTwoPositivs){
    const int a = 2;
    const int b = 3;
    EXPECT_EQ(prod(a,b),6) << "The product is not correct!";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}