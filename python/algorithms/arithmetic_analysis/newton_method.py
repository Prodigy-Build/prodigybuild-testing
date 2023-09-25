import unittest

class TestNewtonMethod(unittest.TestCase):
    def test_newton_method(self):
        self.assertEqual(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3), 2.0945514815423474)
        self.assertEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2), 1.0)
        self.assertEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4), 1.0000000000000102)
        import math
        self.assertEqual(newton(math.sin, math.cos, 1), 0.0)
        self.assertEqual(newton(math.sin, math.cos, 2), 3.141592653589793)
        self.assertEqual(newton(math.cos, lambda x: -math.sin(x), 2), 1.5707963267948966)
        with self.assertRaises(ZeroDivisionError):
            newton(math.cos, lambda x: -math.sin(x), 0)

if __name__ == "__main__":
    unittest.main()