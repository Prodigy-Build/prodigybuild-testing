import unittest

class TestCircleSort(unittest.TestCase):

    def test_circle_sort(self):
        self.assertEqual(circle_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(circle_sort([]), [])
        self.assertEqual(circle_sort([-2, 5, 0, -45]), [-45, -2, 0, 5])
        self.assertTrue(all(sorted(collection) == circle_sort(collection) for collection in ([], [0, 5, 3, 2, 2], [-2, 5, 0, -45])))

    def test_circle_sort_util(self):
        arr = [5,4,3,2,1]
        self.assertTrue(circle_sort_util(arr, 0, 2))
        self.assertEqual(arr, [3, 4, 5, 2, 1])

if __name__ == "__main__":
    unittest.main()