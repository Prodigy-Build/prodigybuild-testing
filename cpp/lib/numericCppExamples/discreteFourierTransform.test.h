```cpp
#include <gtest/gtest.h>

#include "cpp/lib/numericCppExamples/discreteFourierTransform.h"

using namespace IntegralTransforms;

TEST(DiscreteFourierTransformTest, DftTest) {
  CVec<> input = {Complex<>(1, 0), Complex<>(0, 1), Complex<>(-1, 0), Complex<>(0, -1)};
  CVec<> expected = {Complex<>(0, 0), Complex<>(2, 2), Complex<>(0, 0), Complex<>(2, -2)};
  
  CVec<> result = dft(input);
  
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < result.size(); ++i) {
    EXPECT_NEAR(result[i].real(), expected[i].real(), 1e-6);
    EXPECT_NEAR(result[i].imag(), expected[i].imag(), 1e-6);
  }
}

TEST(DiscreteFourierTransformTest, IdftTest) {
  CVec<> input = {Complex<>(0, 0), Complex<>(2, 2), Complex<>(0, 0), Complex<>(2, -2)};
  CVec<> expected = {Complex<>(1, 0), Complex<>(0, 1), Complex<>(-1, 0), Complex<>(0, -1)};
  
  CVec<> result = idft(input);
  
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < result.size(); ++i) {
    EXPECT_NEAR(result[i].real(), expected[i].real(), 1e-6);
    EXPECT_NEAR(result[i].imag(), expected[i].imag(), 1e-6);
  }
}
```