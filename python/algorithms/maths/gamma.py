import math
import unittest
from numpy import inf
from scipy.integrate import quad


def gamma(num: float) -> float:
    """
    https://en.wikipedia.org/wiki/Gamma_function
    In mathematics, the gamma function is one commonly
    used extension of the factorial function to complex numbers.
    The gamma function is defined for all complex numbers except the non-positive
    integers
    >>> gamma(-1)
    Traceback (most recent call last):
        ...
    ValueError: math domain error
    >>> gamma(0)
    Traceback (most recent call last):
        ...
    ValueError: math domain error
    >>> gamma(9)
    40320.0
    >>> from math import gamma as math_gamma
    >>> all(.99999999 < gamma(i) / math_gamma(i) <= 1.000000001
    ...     for i in range(1, 50))
    True
    >>> gamma(-1)/math_gamma(-1) <= 1.000000001
    Traceback (most recent call last):
        ...
    ValueError: math domain error
    >>> gamma(3.3) - math_gamma(3.3) <= 0.00000001
    True
    """
    if num <= 0:
        raise ValueError("math domain error")

    return quad(integrand, 0, inf, args=(num))[0]


def integrand(x: float, z: float) -> float:
    return math.pow(x, z - 1) * math.exp(-x)


class GammaTestCase(unittest.TestCase):
    def test_gamma_negative_input(self):
        with self.assertRaises(ValueError):
            gamma(-1)

    def test_gamma_zero_input(self):
        with self.assertRaises(ValueError):
            gamma(0)

    def test_gamma_positive_input(self):
        self.assertEqual(gamma(9), 40320.0)

    def test_gamma_comparison_with_math_gamma(self):
        from math import gamma as math_gamma
        for i in range(1, 50):
            self.assertTrue(.99999999 < gamma(i) / math_gamma(i) <= 1.000000001)

    def test_gamma_negative_input_comparison_with_math_gamma(self):
        with self.assertRaises(ValueError):
            gamma(-1) / math_gamma(-1)

    def test_gamma_float_input_comparison_with_math_gamma(self):
        self.assertTrue(gamma(3.3) - math_gamma(3.3) <= 0.00000001)


if __name__ == "__main__":
    unittest.main()