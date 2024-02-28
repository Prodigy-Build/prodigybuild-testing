"""
Unit Test cases for odd_even_sort
"""

import unittest

class TestOddEvenSort(unittest.TestCase):
    def test_odd_even_sort(self):
        self.assertEqual(odd_even_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
        self.assertEqual(odd_even_sort([]), [])
        self.assertEqual(odd_even_sort([-10, -1, 10, 2]), [-10, -1, 2, 10])
        self.assertEqual(odd_even_sort([1, 2, 3, 4]), [1, 2, 3, 4])
        self.assertEqual(odd_even_sort([1]), [1])

if __name__ == "__main__":
    unittest.main()