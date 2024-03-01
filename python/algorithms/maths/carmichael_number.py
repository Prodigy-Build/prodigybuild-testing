import unittest

from algorithms.maths.carmichael_number import gcd, power, is_carmichael_number


class TestCarmichaelNumber(unittest.TestCase):
    def test_gcd(self):
        self.assertEqual(gcd(10, 25), 5)
        self.assertEqual(gcd(14, 28), 14)
        self.assertEqual(gcd(21, 14), 7)
        self.assertEqual(gcd(17, 23), 1)

    def test_power(self):
        self.assertEqual(power(2, 3, 5), 3)
        self.assertEqual(power(3, 4, 7), 4)
        self.assertEqual(power(4, 5, 9), 4)
        self.assertEqual(power(5, 6, 11), 1)

    def test_is_carmichael_number(self):
        self.assertTrue(is_carmichael_number(561))
        self.assertTrue(is_carmichael_number(1105))
        self.assertFalse(is_carmichael_number(7))
        self.assertFalse(is_carmichael_number(13))


if __name__ == "__main__":
    unittest.main()