import unittest
from typing import Callable
from area_under_curve import trapezoidal_area

class TestTrapezoidalArea(unittest.TestCase):
    def test_constant_function(self):
        def f(x):
            return 5
        self.assertAlmostEqual(trapezoidal_area(f, 12.0, 14.0, 1000), 10.0, places=3)

    def test_quadratic_function(self):
        def f(x):
            return 9*x**2
        self.assertAlmostEqual(trapezoidal_area(f, -4.0, 0, 10000), 192.0, places=4)
        self.assertAlmostEqual(trapezoidal_area(f, -4.0, 4.0, 10000), 384.0, places=4)

if __name__ == '__main__':
    unittest.main()