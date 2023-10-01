#include <gtest/gtest.h>
#include "../cpp/lib/numericCppExamples/bbpTypeFormula.h"

TEST(BBPTypeFormulaTest, AccuracyTest) {
  ASSERT_NEAR(Spigot::P(1, 16, 10, {0, 1, 4, 5, 6, 10, 11, 12, 13, 14}, 10000), 3.141592653589793, 1e-12);
}