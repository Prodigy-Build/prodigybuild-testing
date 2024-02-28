import unittest

class TestSortMethods(unittest.TestCase):
    def test_merge_sort(self):
        self.assertEqual(merge_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(merge_sort([]), [])
        self.assertEqual(merge_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(merge_sort([10, 17, 3, 2, 15, 5, 10, 3, 17]), [2, 3, 3, 5, 10, 10, 15, 17, 17])
        self.assertEqual(merge_sort([5]), [5])

if __name__ == '__main__':
    unittest.main()