```cpp/examples/AutomaticDifferentiation/main.cpp``` updated code:

```cpp
#include <iostream>
#include <cmath>

double pow(double base, double exponent) {
  return std::pow(base, exponent);
}

class Dual {
public:
  double real;
  double dual;

  Dual(double realValue, double dualValue) : real(realValue), dual(dualValue) {}

  Dual operator+(const Dual& other) const {
    return Dual(real + other.real, dual + other.dual);
  }

  Dual operator*(const Dual& other) const {
    return Dual(real * other.real, real * other.dual + other.real * dual);
  }
};

int main() {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  std::cout << "Derivative of 5x^2+4x+1 at x = 2 is: " << f.dual << std::endl;
  return 0;
}
```