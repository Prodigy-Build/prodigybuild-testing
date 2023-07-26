. 

#ifndef LAGRANGEINTERPOLATION_H
#define LAGRANGEINTERPOLATION_H

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

namespace Interpolation {
/** A struct for storing x and y values. */
template <typename T = long double>
struct Data {
  Data(std::vector<T> x, std::vector<T> y) {
    assert(x.size() == y.size());
    this->x = x;
    this->y = y;
    this->size = x.size();
  }

  std::vector<T> x;
  std::vector<T> y;
  unsigned long size;
};

/**
 * Lagrange polynomial.
 *
 * @param data A data.
 *
 * @return Lagrange interpolation polynomial.
 */
template <typename T>
std::function<T(T)> lagrangePoly(const Data<T> &data) {
  auto polynomial = [data](T x) {
    auto sum = 0.0;
    for (auto j = 0; j < data.size; j++) {
      auto yj = data.y[j];
      auto inner_prod = 1.0;
      for (auto k = 0; k < data.size; k++) {
        if (k != j) {
          inner_prod *= (x - data.x[k]) / (data.x[j] - data.x[k]);
        }
      }
      sum += yj * inner_prod;
    };

    return sum;
  };

  return polynomial;
}

// Unit tests
TEST(LagrangeInterpolation, Test1) {
  std::vector<long double> x = {1, 2, 3};
  std::vector<long double> y = {2, 4, 6};
  Interpolation::Data<long double> data(x, y);
  auto poly = lagrangePoly(data);
  EXPECT_EQ(poly(2.5), 5.0);
}

TEST(LagrangeInterpolation, Test2) {
  std::vector<long double> x = {1, 2, 3};
  std::vector<long double> y = {2, 4, 6};
  Interpolation::Data<long double> data(x, y);
  auto poly = lagrangePoly(data);
  EXPECT_EQ(poly(1.5), 3.0);
}

}  // namespace Interpolation
#endif  // LAGRANGEINTERPOLATION_H