#include "../../lib/numericCppExamplesLib/dualNumbers.h"
#include <cassert>

void test_automatic_differentiation() {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;

  assert(f.real == 21); // Check the real part of f
  assert(f.dual == 14); // Check the dual part of f
}

int main() {
  test_automatic_differentiation();

  std::cout << "All tests passed!" << std::endl;
  return 0;
}