import unittest

class TestBogoSort(unittest.TestCase):
    def test_bogo_sort(self):
        self.assertEqual(bogo_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(bogo_sort([]), [])
        self.assertEqual(bogo_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(bogo_sort([1]), [1])
        self.assertEqual(bogo_sort([3,2,1]), [1,2,3])

if __name__ == "__main__":
    unittest.main()