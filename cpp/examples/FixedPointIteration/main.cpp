#include <iostream>
#include <functional>
#include <cmath>

void fixedPointIter(double p0, double tol, unsigned long N, std::function<double(double)> g) {
  double p = p0;
  for (unsigned long i = 0; i < N; i++) {
    double pPrev = p;
    p = g(pPrev);
    if (std::abs(p - pPrev) < tol) {
      break;
    }
  }
}

int main(int argc, const char* argv[]) {
  // Calculate g(x) = x - (x^2 - 2) / (2*x)
  double p0 = 2;
  double tol = 1e-10;
  unsigned long N0 = 100;
  std::function<double(double)> g = [](double x) {
    return x - ((std::pow(x, 2) - 2) / (2 * x));
  };
  fixedPointIter(p0, tol, N0, g);
  return 0;
}