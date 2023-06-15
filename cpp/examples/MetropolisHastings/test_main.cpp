

#include <iostream>
#include "../../lib/numericCppExamplesLib/metropolisHastings.h"
#include <gtest/gtest.h>

double target(const double& x) { return x < 0 ? 0 : std::exp(-x); }

TEST(MetropolisHastings, Test1) {
  std::vector<long double> nums = generate<long double>(target, 10000, 2500);
  for (auto num : nums) {
    EXPECT_GE(num, 0);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}