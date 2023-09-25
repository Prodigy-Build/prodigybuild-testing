#ifndef AUTOMATIC_DIFFERENTIATION_MAIN_H
#define AUTOMATIC_DIFFERENTIATION_MAIN_H

#include "../../lib/numericCppExamplesLib/dualNumbers.h"
#include <iostream>

int main() {
  Dual x(2, 1);
  Dual f = 5 * pow(x, 2) + 4 * x + 1;
  std::cout << "Derivative of 5x^2+4x+1 at x = 2 is: " << f.dual << std::endl;
  return 0;
}

#endif //AUTOMATIC_DIFFERENTIATION_MAIN_H