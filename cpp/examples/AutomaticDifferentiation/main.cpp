#include "../../lib/numericCppExamplesLib/dualNumbers.h"
#include <gtest/gtest.h>

TEST(AutomaticDifferentiation, TestDerivativeCalculation) {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  ASSERT_EQ(f.dual, 14);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}