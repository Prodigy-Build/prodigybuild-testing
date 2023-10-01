import unittest
from newton_method import newton, f, f1

class TestNewtonMethod(unittest.TestCase):
    def test_newton(self):
        self.assertAlmostEqual(newton(f, f1, 3), 2.0945514815423474)
        self.assertAlmostEqual(newton(f, f1, -2), 1.0)
        self.assertAlmostEqual(newton(f, f1, -4), 1.0000000000000102)
        self.assertAlmostEqual(newton(math.sin, math.cos, 1), 0.0)
        self.assertAlmostEqual(newton(math.sin, math.cos, 2), 3.141592653589793)
        with self.assertRaises(ZeroDivisionError):
            newton(math.cos, lambda x: -math.sin(x), 0)

if __name__ == "__main__":
    unittest.main()