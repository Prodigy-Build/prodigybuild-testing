import math
import unittest


def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp


class TestNewtonForwardInterpolation(unittest.TestCase):
    def test_ucal(self):
        self.assertAlmostEqual(ucal(1, 2), 0)
        self.assertAlmostEqual(ucal(1.1, 2), 0.11000000000000011)
        self.assertAlmostEqual(ucal(1.2, 2), 0.23999999999999994)

    def test_main(self):
        self.assertEqual(main(), None)


if __name__ == '__main__':
    unittest.main()