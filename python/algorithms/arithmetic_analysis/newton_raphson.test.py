from decimal import Decimal
import unittest


def newton_raphson(
    func: str, a: float | Decimal, precision: float = 10**-10
) -> float:
    x = a
    while True:
        x = Decimal(x) - (Decimal(eval(func)) / Decimal(eval(str(diff(func)))))
        if abs(eval(func)) < precision:
            return float(x)


class TestNewtonRaphson(unittest.TestCase):

    def test_sin_function(self):
        result = newton_raphson("sin(x)", 2)
        self.assertAlmostEqual(result, 3.1415926536808043)

    def test_quadratic_function(self):
        result = newton_raphson("x**2 - 5*x + 2", 0.4)
        self.assertAlmostEqual(result, 0.4384471871911695)

    def test_square_root_function(self):
        result = newton_raphson("x**2 - 5", 0.1)
        self.assertAlmostEqual(result, 2.23606797749979)

    def test_logarithmic_function(self):
        result = newton_raphson("log(x)- 1", 2)
        self.assertAlmostEqual(result, 2.718281828458938)

if __name__ == "__main__":
    unittest.main()