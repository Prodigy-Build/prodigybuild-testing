import unittest
from numpy import exp, pi, sqrt


def gaussian(x, mu: float = 0.0, sigma: float = 1.0) -> int:
    return 1 / sqrt(2 * pi * sigma**2) * exp(-((x - mu) ** 2) / (2 * sigma**2))


class TestGaussian(unittest.TestCase):
    def test_gaussian(self):
        self.assertAlmostEqual(gaussian(1), 0.24197072451914337)
        self.assertAlmostEqual(gaussian(24), 3.342714441794458e-126)
        self.assertAlmostEqual(gaussian(1, 4, 2), 0.06475879783294587)
        self.assertAlmostEqual(gaussian(1, 5, 3), 0.05467002489199788)
        self.assertAlmostEqual(gaussian(15), 5.530709549844416e-50)
        self.assertRaises(TypeError, gaussian, [1, 2, 'string'])
        self.assertRaises(TypeError, gaussian, 'hello world')
        self.assertRaises(OverflowError, gaussian, 10**234)
        self.assertAlmostEqual(gaussian(10**-326), 0.3989422804014327)
        self.assertAlmostEqual(gaussian(2523, mu=234234, sigma=3425), 0.0)


if __name__ == "__main__":
    unittest.main()