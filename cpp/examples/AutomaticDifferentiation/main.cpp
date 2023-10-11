#include "../../lib/numericCppExamplesLib/dualNumbers.h"
#include <cassert>

void test_derivative() {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  assert(f.dual == 14);
}

int main() {
  test_derivative();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}