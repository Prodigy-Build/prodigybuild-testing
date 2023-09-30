```python
import unittest
from typing import Optional
from math import isclose, sin, cos


def newton(
        function: Callable[[float], float],
        derivative: Callable[[float], float],
        starting_int: int
) -> float:
    prev_guess = float(starting_int)
    while True:
        try:
            next_guess = prev_guess - function(prev_guess) / derivative(prev_guess)
        except ZeroDivisionError:
            raise ZeroDivisionError("Could not find root") from None
        if abs(prev_guess - next_guess) < 10**-5:
            return next_guess
        prev_guess = next_guess


class TestNewtonMethod(unittest.TestCase):
    def test_newton_1(self):
        self.assertTrue(isclose(newton(
            lambda x: x ** 3 - 2 * x - 5,
            lambda x: 3 * x ** 2 - 2,
            3),
            2.0945514815423474))

    def test_newton_2(self):
        self.assertTrue(isclose(newton(
            lambda x: x ** 3 - 1,
            lambda x: 3 * x ** 2,
            -2),
            1.0))

    def test_newton_3(self):
        self.assertTrue(isclose(newton(
            lambda x: x ** 3 - 1,
            lambda x: 3 * x ** 2,
            -4),
            1.0000000000000102))

    def test_newton_4(self):
        self.assertTrue(isclose(newton(
            sin,
            cos,
            1),
            0.0))

    def test_newton_5(self):
        self.assertTrue(isclose(newton(
            sin,
            cos,
            2),
            3.141592653589793))

    def test_newton_6(self):
        self.assertTrue(isclose(newton(
            cos,
            lambda x: -sin(x),
            2),
            1.5707963267948966))

    def test_newton_7(self):
        with self.assertRaises(ZeroDivisionError) as context:
            newton(cos, lambda x: -sin(x), 0)
        self.assertEqual(str(context.exception), "Could not find root")


if __name__ == "__main__":
    unittest.main()