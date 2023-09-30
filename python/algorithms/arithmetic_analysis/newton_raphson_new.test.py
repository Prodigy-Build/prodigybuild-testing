import unittest
from unittest import TestCase
from sympy import diff, lambdify, symbols
from sympy.functions import *


def newton_raphson(
    function: str,
    starting_point: complex,
    variable: str = "x",
    precision: float = 10 ** -10,
    multiplicity: int = 1,
) -> complex:
    x = symbols(variable)
    func = lambdify(x, function)
    diff_function = lambdify(x, diff(function, x))

    prev_guess = starting_point

    while True:
        if diff_function(prev_guess) != 0:
            next_guess = prev_guess - multiplicity * func(prev_guess) / diff_function(
                prev_guess
            )
        else:
            raise ZeroDivisionError("Could not find root") from None

        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess


class TestNewtonRaphson(TestCase):

    def test_sine_function(self):
        self.assertAlmostEqual(newton_raphson("sin(x)", 2), 3.141592653589793)

    def test_polynomial_function(self):
        self.assertAlmostEqual(newton_raphson("x**4 -5", 0.4 + 5j), (-7.52316384526264e-37 + 1.4953487812212207j))

    def test_logarithm_function(self):
        self.assertAlmostEqual(newton_raphson("log(y) - 1", 2, variable='y'), 2.7182818284590455)

    def test_exponential_function(self):
        self.assertAlmostEqual(newton_raphson("exp(x) - 1", 10, precision=0.005), 1.2186556186174883e-10)

    def test_cosine_function(self):
        with self.assertRaises(ZeroDivisionError):
            newton_raphson("cos(x)", 0)


if __name__ == '__main__':
    unittest.main()