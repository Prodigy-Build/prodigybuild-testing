

#include <iomanip>
#include <iostream>
#include "../../lib/numericCppExamplesLib/bbpTypeFormula.h"
#include "../../lib/numericCppExamplesLib/discreteFourierTransform.h"
#include "gtest/gtest.h"

TEST(BBPTypeFormula, PiApproximation) {
  EXPECT_NEAR(P(1, 16, 8, std::vector<int>{4, 0, 0, -2, -1, -1, 0, 0}, 10), 3.1415926536, 0.00001);
}

TEST(BBPTypeFormula, Ln3Approximation) {
  EXPECT_NEAR(P(1, 4, 2, std::vector<int>{1, 0}, 10), 1.098612289, 0.00001);
}

TEST(DiscreteFourierTransform, DFT) {
  CVec<> x({1, 2, 3, 4, 5, 6, 7, 8});
  auto y = dft(x);
  std::vector<std::complex<double>> expected_y = {36.0000000000+0.0000000000i, -4.0000000000+9.6568542501i, -4.0000000000+4.0000000000i, -4.0000000000+1.6568542501i, -4.0000000000+0.0000000000i, -4.0000000000-1.6568542501i, -4.0000000000-4.0000000000i, -4.0000000000-9.6568542501i};
  for (int i = 0; i < 8; i++) {
    EXPECT_NEAR(y[i].real(), expected_y[i].real(), 0.00001);
    EXPECT_NEAR(y[i].imag(), expected_y[i].imag(), 0.00001);
  }
}

TEST(DiscreteFourierTransform, IDFT) {
  CVec<> x({1, 2, 3, 4, 5, 6, 7, 8});
  auto y = dft(x);
  auto x_ = idft(y);
  for (int i = 0; i < 8; i++) {
    EXPECT_NEAR(x_[i].real(), x[i].real(), 0.00001);
    EXPECT_NEAR(x_[i].imag(), x[i].imag(), 0.00001);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
