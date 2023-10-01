from decimal import Decimal
from math import *

from sympy import diff


def newton_raphson(
    func: str, a: float | Decimal, precision: float = 10**-10
) -> float:
    x = a
    while True:
        x = Decimal(x) - (Decimal(eval(func)) / Decimal(eval(str(diff(func)))))
        if abs(eval(func)) < precision:
            return float(x)


import unittest


class TestNewtonRaphson(unittest.TestCase):
    def test_newton_raphson_sin(self):
        self.assertAlmostEqual(newton_raphson("sin(x)", 2), 3.1415926536808043, places=10)

    def test_newton_raphson_polynomial(self):
        self.assertAlmostEqual(newton_raphson("x**2 - 5*x + 2", 0.4), 0.4384471871911695, places=10)

    def test_newton_raphson_square_root(self):
        self.assertAlmostEqual(newton_raphson("x**2 - 5", 0.1), 2.23606797749979, places=10)

    def test_newton_raphson_log(self):
        self.assertAlmostEqual(newton_raphson("log(x)- 1", 2), 2.718281828458938, places=10)


if __name__ == "__main__":
    unittest.main()