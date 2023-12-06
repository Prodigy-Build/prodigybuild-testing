import unittest

class TestModularDivision(unittest.TestCase):

    def test_modular_division(self):
        self.assertEqual(modular_division(4, 8, 5), 2)
        self.assertEqual(modular_division(3, 8, 5), 1)
        self.assertEqual(modular_division(4, 11, 5), 4)

    def test_invert_modulo(self):
        self.assertEqual(invert_modulo(2, 5), 3)
        self.assertEqual(invert_modulo(8, 7), 1)

    def test_modular_division2(self):
        self.assertEqual(modular_division2(4, 8, 5), 2)
        self.assertEqual(modular_division2(3, 8, 5), 1)
        self.assertEqual(modular_division2(4, 11, 5), 4)

    def test_extended_gcd(self):
        self.assertEqual(extended_gcd(10, 6), (2, -1, 2))
        self.assertEqual(extended_gcd(7, 5), (1, -2, 3))

    def test_extended_euclid(self):
        self.assertEqual(extended_euclid(10, 6), (-1, 2))
        self.assertEqual(extended_euclid(7, 5), (-2, 3))

    def test_greatest_common_divisor(self):
        self.assertEqual(greatest_common_divisor(7, 5), 1)
        self.assertEqual(greatest_common_divisor(121, 11), 11)


if __name__ == '__main__':
    unittest.main()