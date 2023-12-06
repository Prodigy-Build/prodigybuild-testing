```python
import unittest
from diophantine_equation import diophantine, diophantine_all_soln


class TestDiophantine(unittest.TestCase):
    def test_diophantine(self):
        self.assertEqual(diophantine(10, 6, 14), (-7.0, 14.0))
        self.assertEqual(diophantine(391, 299, -69), (9.0, -12.0))


class TestDiophantineAllSoln(unittest.TestCase):
    def test_diophantine_all_soln(self):
        result1 = []
        diophantine_all_soln(10, 6, 14)
        self.assertEqual(result1, [(-7.0, 14.0), (-4.0, 9.0)])

        result2 = []
        diophantine_all_soln(10, 6, 14, 4)
        self.assertEqual(result2, [(-7.0, 14.0), (-4.0, 9.0), (-1.0, 4.0), (2.0, -1.0)])

        result3 = []
        diophantine_all_soln(391, 299, -69, n = 4)
        self.assertEqual(result3, [(9.0, -12.0), (22.0, -29.0), (35.0, -46.0), (48.0, -63.0)])


if __name__ == "__main__":
    unittest.main()
```