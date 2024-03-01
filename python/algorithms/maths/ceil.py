import math
import unittest

from algorithms.maths.ceil import ceil


class CeilTestCase(unittest.TestCase):
    def test_ceil(self):
        self.assertEqual(ceil(1), math.ceil(1))
        self.assertEqual(ceil(-1), math.ceil(-1))
        self.assertEqual(ceil(0), math.ceil(0))
        self.assertEqual(ceil(-0), math.ceil(-0))
        self.assertEqual(ceil(1.1), math.ceil(1.1))
        self.assertEqual(ceil(-1.1), math.ceil(-1.1))
        self.assertEqual(ceil(1.0), math.ceil(1.0))
        self.assertEqual(ceil(-1.0), math.ceil(-1.0))
        self.assertEqual(ceil(1_000_000_000), math.ceil(1_000_000_000))


if __name__ == "__main__":
    unittest.main()