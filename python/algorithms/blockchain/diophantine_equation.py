```python
import unittest
from diophantine_equation import diophantine, diophantine_all_soln, greatest_common_divisor, extended_gcd

class DiophantineEquationTests(unittest.TestCase):

    def test_diophantine(self):
        result = diophantine(10, 6, 14)
        self.assertEqual(result, (-7.0, 14.0))

        result = diophantine(391, 299, -69)
        self.assertEqual(result, (9.0, -12.0))

    def test_diophantine_all_soln(self):
        result = diophantine_all_soln(10, 6, 14, n=2)
        self.assertEqual(result, [(-7.0, 14.0), (-4.0, 9.0)])

        result = diophantine_all_soln(10, 6, 14, n=4)
        self.assertEqual(result, [(-7.0, 14.0), (-4.0, 9.0), (-1.0, 4.0), (2.0, -1.0)])

        result = diophantine_all_soln(391, 299, -69, n=4)
        self.assertEqual(result, [(9.0, -12.0), (22.0, -29.0), (35.0, -46.0), (48.0, -63.0)])

    def test_greatest_common_divisor(self):
        result = greatest_common_divisor(7, 5)
        self.assertEqual(result, 1)

        result = greatest_common_divisor(121, 11)
        self.assertEqual(result, 11)

    def test_extended_gcd(self):
        result = extended_gcd(10, 6)
        self.assertEqual(result, (2, -1, 2))

        result = extended_gcd(7, 5)
        self.assertEqual(result, (1, -2, 3))

if __name__ == '__main__':
    unittest.main()
```