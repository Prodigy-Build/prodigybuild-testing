import unittest
from wiggle_sort import wiggle_sort


class TestWiggleSort(unittest.TestCase):
    
    def test_wiggle_sort(self):
        self.assertEqual(wiggle_sort([0, 5, 3, 2, 2]), [0, 5, 2, 3, 2])
        self.assertEqual(wiggle_sort([]), [])
        self.assertEqual(wiggle_sort([-2, -5, -45]), [-45, -2, -5])
        self.assertEqual(wiggle_sort([-2.1, -5.68, -45.11]), [-45.11, -2.1, -5.68])
        self.assertEqual(wiggle_sort([3,5,2,1,6,4]), [3, 5, 1, 6, 2, 4])

if __name__ == '__main__':
    unittest.main()