#include <iostream>

double pow(double x, int n) {
  double result = 1;
  for (int i = 0; i < n; i++) {
    result *= x;
  }
  return result;
}

class Dual {
public:
  double value;
  double dual;

  Dual(double v, double d) : value(v), dual(d) {}

  Dual operator+(const Dual& other) {
    return Dual(value + other.value, dual + other.dual);
  }

  Dual operator*(const Dual& other) {
    return Dual(value * other.value, value * other.dual + dual * other.value);
  }
};

int main() {
  Dual x(2, 1);
  Dual f = 5 * pow(x.value, 2) + 4 * x + 1;
  std::cout << "Derivative of 5x^2 + 4x + 1 at x = 2 is: " << f.dual << std::endl;
  return 0;
}