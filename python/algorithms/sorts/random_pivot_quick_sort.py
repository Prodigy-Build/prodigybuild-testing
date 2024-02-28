import unittest
import random

class TestQuickSort(unittest.TestCase):
    def setUp(self):
        self.random_list = [random.randint(0, 100) for _ in range(10)]
        
    def test_quick_sort_random(self):
        sorted_list = sorted(self.random_list)
        quick_sort_random(self.random_list, 0, len(self.random_list))
        self.assertEqual(self.random_list, sorted_list)

    def test_quick_sort_random_empty(self):
        empty_list = []
        quick_sort_random(empty_list, 0, len(empty_list))
        self.assertEqual(empty_list, [])

    def test_quick_sort_random_single(self):
        single_list = [7]
        quick_sort_random(single_list, 0, len(single_list))
        self.assertEqual(single_list, [7])
        
    def test_quick_sort_random_duplicate(self):
        duplicate_list = [7, 7, 7, 7, 7]
        quick_sort_random(duplicate_list, 0, len(duplicate_list))
        self.assertEqual(duplicate_list, [7, 7, 7, 7, 7])
        
if __name__ == '__main__':
    unittest.main()