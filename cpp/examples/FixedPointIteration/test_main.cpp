

//
//  main.cpp
//  BBPTypeFormula
//
//

#include <iostream>
#include "../../lib/numericCppExamplesLib/BBPTypeFormula.h"
#include "../../lib/numericCppExamplesLib/test_utils.h"

int main(int argc, const char* argv[]) {
  // Calculate pi using BBP type formula
  double pi = BBPTypeFormula(1e-10);
  std::cout << "pi = " << pi << std::endl;
  TEST_ASSERT_NEAR_EPS(pi, 3.14159265358979323846, 1e-10);
  return 0;
}

