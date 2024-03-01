import math
import unittest

def res(x, y):
    if 0 not in (x, y):
        return y * math.log10(x)
    else:
        if x == 0:
            return 0
        elif y == 0:
            return 1
    raise AssertionError("This should never happen")

class TestLargestOfVeryLargeNumbers(unittest.TestCase):
    def test_res(self):
        self.assertEqual(res(2, 3), 3 * math.log10(2))
        self.assertEqual(res(0, 5), 0)
        self.assertEqual(res(2, 0), 1)
        self.assertEqual(res(0, 0), 1)

if __name__ == "__main__":
    unittest.main()