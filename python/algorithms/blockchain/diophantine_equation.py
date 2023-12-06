from __future__ import annotations
from typing import Tuple
import unittest

def diophantine(a: int, b: int, c: int) -> Tuple[float, float]:
    (d, x, y) = extended_gcd(a, b)
    r = c / d
    return (r * x, r * y)


def diophantine_all_soln(a: int, b: int, c: int, n: int = 2) -> None:
    (x0, y0) = diophantine(a, b, c)
    d = greatest_common_divisor(a, b)
    p = a // d
    q = b // d

    for i in range(n):
        x = x0 + i * q
        y = y0 - i * p
        print(x, y)


def greatest_common_divisor(a: int, b: int) -> int:
    if a < b:
        a, b = b, a

    while a % b != 0:
        a, b = b, a % b

    return b


def extended_gcd(a: int, b: int) -> Tuple[int, int, int]:
    if b == 0:
        d, x, y = a, 1, 0
    else:
        (d, p, q) = extended_gcd(b, a % b)
        x = q
        y = p - q * (a // b)

    return (d, x, y)


class TestDiophantine(unittest.TestCase):

    def test_diophantine(self):
        self.assertEqual(diophantine(10, 6, 14), (-7.0, 14.0))
        self.assertEqual(diophantine(391, 299, -69), (9.0, -12.0))

    def test_diophantine_all_soln(self):
        self.assertEqual(diophantine_all_soln(10, 6, 14), [(-7.0, 14.0), (-4.0, 9.0)])
        self.assertEqual(
            diophantine_all_soln(10, 6, 14, 4),
            [(-7.0, 14.0), (-4.0, 9.0), (-1.0, 4.0), (2.0, -1.0)]
        )
        self.assertEqual(
            diophantine_all_soln(391, 299, -69, n=4),
            [(9.0, -12.0), (22.0, -29.0), (35.0, -46.0), (48.0, -63.0)]
        )

    def test_greatest_common_divisor(self):
        self.assertEqual(greatest_common_divisor(7, 5), 1)
        self.assertEqual(greatest_common_divisor(121, 11), 11)

    def test_extended_gcd(self):
        self.assertEqual(extended_gcd(10, 6), (2, -1, 2))
        self.assertEqual(extended_gcd(7, 5), (1, -2, 3))


if __name__ == "__main__":
    unittest.main()