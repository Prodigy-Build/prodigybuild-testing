import unittest

class TestMergeInsertionSort(unittest.TestCase):
    
    def test_merge_insertion_sort(self):
        self.assertEqual(merge_insertion_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(merge_insertion_sort([99]), [99])
        self.assertEqual(merge_insertion_sort([-2, -5, -45]), [-45, -5, -2])
        import itertools
        permutations = list(itertools.permutations([0, 1, 2, 3, 4]))
        self.assertTrue(all(merge_insertion_sort(p) == [0, 1, 2, 3, 4] for p in permutations))

    def test_binary_search_insertion(self):
        self.assertEqual(binary_search_insertion([1, 2, 7, 9, 10], 4), [1, 2, 4, 7, 9, 10])

    def test_merge(self):
        self.assertEqual(merge([[1, 6], [9, 10]], [[2, 3], [4, 5], [7, 8]]), [[1, 6], [2, 3], [4, 5], [7, 8], [9, 10]])

    def test_sortlist_2d(self):
        self.assertEqual(sortlist_2d([[9, 10], [1, 6], [7, 8], [2, 3], [4, 5]]), [[1, 6], [2, 3], [4, 5], [7, 8], [9, 10]])

if __name__ == '__main__':
    unittest.main()