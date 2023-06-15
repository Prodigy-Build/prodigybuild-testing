

#include "../../lib/numericCppExamplesLib/dualNumbers.h"
#include <gtest/gtest.h>

TEST(DualNumberTest, DerivativeTest) {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  EXPECT_EQ(f.dual, 18);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}