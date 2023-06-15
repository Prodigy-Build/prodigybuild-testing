

#include "../../lib/numericCppExamplesLib/lagrangeInterpolation.h"
#include "../../lib/numericCppExamplesLib/metropolisHastings.h"
#include <gtest/gtest.h>

TEST(LagrangeInterpolation, Test1) {
  Data<long double> data1{std::vector<long double>{1, 2, 3},
                         std::vector<long double>{1, 4, 9}};
  auto poly1 = lagrangePoly(data1);
  EXPECT_EQ(poly1(2), 4);
}

TEST(LagrangeInterpolation, Test2) {
  Data<long double> data2{std::vector<long double>{-1, 0, 1, 2},
                         std::vector<long double>{3, -4, 5, -6}};
  auto poly2 = lagrangePoly(data2);
  EXPECT_EQ(poly2(0.5), 0.5);
}

