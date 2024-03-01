import math
import unittest

from algorithms.maths.floor import floor


class FloorTestCase(unittest.TestCase):
    def test_floor_positive_integer(self):
        self.assertEqual(floor(1), math.floor(1))

    def test_floor_negative_integer(self):
        self.assertEqual(floor(-1), math.floor(-1))

    def test_floor_zero(self):
        self.assertEqual(floor(0), math.floor(0))

    def test_floor_negative_zero(self):
        self.assertEqual(floor(-0), math.floor(-0))

    def test_floor_positive_float(self):
        self.assertEqual(floor(1.1), math.floor(1.1))

    def test_floor_negative_float(self):
        self.assertEqual(floor(-1.1), math.floor(-1.1))

    def test_floor_positive_integer_float(self):
        self.assertEqual(floor(1.0), math.floor(1.0))

    def test_floor_negative_integer_float(self):
        self.assertEqual(floor(-1.0), math.floor(-1.0))

    def test_floor_large_number(self):
        self.assertEqual(floor(1_000_000_000), math.floor(1_000_000_000))


if __name__ == "__main__":
    unittest.main()