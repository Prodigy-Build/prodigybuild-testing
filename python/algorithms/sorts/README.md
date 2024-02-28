import unittest
from sorting_algorithms import bubble_sort, quick_sort, merge_sort 

class TestSortingAlgorithms(unittest.TestCase):

    def setUp(self):
        self.list1 = [7, 1, 6, 3, 2, 8, 4, 5]
        self.list2 = [37, 22, 45, 79, 32, 65, 21, 83]

    def test_bubble_sort(self):
        result = bubble_sort(self.list1)
        self.assertEqual(result, [1, 2, 3, 4, 5, 6, 7, 8])

        result = bubble_sort(self.list2)
        self.assertEqual(result, [21, 22, 32, 37, 45, 65, 79, 83])

    def test_quick_sort(self):
        result = quick_sort(self.list1)
        self.assertEqual(result, [1, 2, 3, 4, 5, 6, 7, 8])

        result = quick_sort(self.list2)
        self.assertEqual(result, [21, 22, 32, 37, 45, 65, 79, 83])

    def test_merge_sort(self):
        result = merge_sort(self.list1)
        self.assertEqual(result, [1, 2, 3, 4, 5, 6, 7, 8])

        result = merge_sort(self.list2)
        self.assertEqual(result, [21, 22, 32, 37, 45, 65, 79, 83])

if __name__ == "__main__":
    unittest.main()