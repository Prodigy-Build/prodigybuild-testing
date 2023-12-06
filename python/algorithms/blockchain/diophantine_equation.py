import unittest

class TestDiophantineEquation(unittest.TestCase):
    def test_diophantine(self):
        self.assertEqual(diophantine(10, 6, 14), (-7.0, 14.0))
        self.assertEqual(diophantine(391, 299, -69), (9.0, -12.0))

    def test_diophantine_all_soln(self):
        expected_soln_1 = [
            (-7.0, 14.0),
            (-4.0, 9.0)
        ]
        self.assertEqual(diophantine_all_soln(10, 6, 14), expected_soln_1)

        expected_soln_2 = [
            (-7.0, 14.0),
            (-4.0, 9.0),
            (-1.0, 4.0),
            (2.0, -1.0)
        ]
        self.assertEqual(diophantine_all_soln(10, 6, 14, 4), expected_soln_2)

        expected_soln_3 = [
            (9.0, -12.0),
            (22.0, -29.0),
            (35.0, -46.0),
            (48.0, -63.0)
        ]
        self.assertEqual(diophantine_all_soln(391, 299, -69, 4), expected_soln_3)

    def test_greatest_common_divisor(self):
        self.assertEqual(greatest_common_divisor(7, 5), 1)
        self.assertEqual(greatest_common_divisor(121, 11), 11)

    def test_extended_gcd(self):
        self.assertEqual(extended_gcd(10, 6), (2, -1, 2))
        self.assertEqual(extended_gcd(7, 5), (1, -2, 3))

if __name__ == '__main__':
    unittest.main()