```cpp
#ifndef DISCRETEFOURIERTRANSFORM_H
#define DISCRETEFOURIERTRANSFORM_H

#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

namespace IntegralTransforms {
template <typename T = long double>
using Complex = std::complex<T>;

template <typename T = long double>
using CVec = std::vector<std::complex<T>>;

CVec<> dft(const CVec<>& input) {
  const auto N = input.size();
  CVec<> result(N, Complex<> (0.0, 0.0));
  for (auto n = 0; n < N; n++) {
    auto real = 0.0;
    auto img = 0.0;
    for (auto k = 0; k < N; k++) {
      auto angle = 2 * M_PI * k * n / N;
      real +=
          input[k].real() * std::cos(angle) + input[k].imag() * std::sin(angle);
      img +=
          input[k].imag() * std::cos(angle) - input[k].real() * std::sin(angle);
    }
    result[n] = Complex<>(real, img);
  }
  return result;
}

CVec<> idft(const CVec<>& input) {
  const auto N = input.size();
  CVec<> result(N, Complex<> (0.0, 0.0));
  for (auto n = 0; n < N; n++) {
    auto real = 0.0;
    auto img = 0.0;
    for (auto k = 0; k < N; k++) {
      auto angle = 2 * M_PI * k * n / N;
      real +=
          input[k].real() * std::cos(angle) - input[k].imag() * std::sin(angle);
      img +=
          input[k].imag() * std::cos(angle) + input[k].real() * std::sin(angle);
    }
    result[n] = Complex<>(real / N, img / N);
  }
  return result;
}
}  // namespace IntegralTransforms
#endif  // DISCRETEFOURIERTRANSFORM_H
```