#include <iostream>
#include <cassert>
#include "../../lib/numericCppExamplesLib/dualNumbers.h"

void testDerivative() {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  assert(f.dual == 14);
}

int main() {
  testDerivative();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}