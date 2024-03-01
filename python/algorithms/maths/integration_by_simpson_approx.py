import unittest

class TestSimpsonIntegration(unittest.TestCase):
    def test_simpson_integration(self):
        self.assertAlmostEqual(simpson_integration(lambda x : x*x, 1, 2, 3), 2.333)
        self.assertRaises(AssertionError, simpson_integration, lambda x : x*x, 'wrong_input', 2, 3)
        self.assertRaises(AssertionError, simpson_integration, lambda x : x*x, 1, 'wrong_input', 3)
        self.assertRaises(AssertionError, simpson_integration, lambda x : x*x, 1, 2, 'wrong_input')
        self.assertRaises(AssertionError, simpson_integration, 'wrong_input', 2, 3, 4)
        self.assertAlmostEqual(simpson_integration(lambda x : x*x, 3.45, 3.2, 1), -2.8)
        self.assertRaises(AssertionError, simpson_integration, lambda x : x*x, 3.45, 3.2, 0)
        self.assertRaises(AssertionError, simpson_integration, lambda x : x*x, 3.45, 3.2, -1)

unittest.main()