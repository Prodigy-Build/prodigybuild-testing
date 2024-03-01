The updated code for the file "python/algorithms/maths/polynomial_evaluation.py" with added unit test cases is as follows:

```python
from collections.abc import Sequence
import unittest


def evaluate_poly(poly: Sequence[float], x: float) -> float:
    """Evaluate a polynomial f(x) at specified point x and return the value.

    Arguments:
    poly -- the coefficients of a polynomial as an iterable in order of
            ascending degree
    x -- the point at which to evaluate the polynomial

    >>> evaluate_poly((0.0, 0.0, 5.0, 9.3, 7.0), 10.0)
    79800.0
    """
    return sum(c * (x**i) for i, c in enumerate(poly))


def horner(poly: Sequence[float], x: float) -> float:
    """Evaluate a polynomial at specified point using Horner's method.

    In terms of computational complexity, Horner's method is an efficient method
    of evaluating a polynomial. It avoids the use of expensive exponentiation,
    and instead uses only multiplication and addition to evaluate the polynomial
    in O(n), where n is the degree of the polynomial.

    https://en.wikipedia.org/wiki/Horner's_method

    Arguments:
    poly -- the coefficients of a polynomial as an iterable in order of
            ascending degree
    x -- the point at which to evaluate the polynomial

    >>> horner((0.0, 0.0, 5.0, 9.3, 7.0), 10.0)
    79800.0
    """
    result = 0.0
    for coeff in reversed(poly):
        result = result * x + coeff
    return result


class PolynomialEvaluationTestCase(unittest.TestCase):
    def test_evaluate_poly(self):
        poly = (0.0, 0.0, 5.0, 9.3, 7.0)
        x = 10.0
        expected_result = 79800.0
        self.assertEqual(evaluate_poly(poly, x), expected_result)

    def test_horner(self):
        poly = (0.0, 0.0, 5.0, 9.3, 7.0)
        x = 10.0
        expected_result = 79800.0
        self.assertEqual(horner(poly, x), expected_result)


if __name__ == "__main__":
    unittest.main()
```

Please note that the code provided above includes the original code and the added unit test cases.