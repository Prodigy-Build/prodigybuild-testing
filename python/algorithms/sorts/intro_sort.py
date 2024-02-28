import unittest

class TestSortMethods(unittest.TestCase):

    def test_insertion_sort(self):
        self.assertEqual(insertion_sort([4, 2, 6, 8, 1, 7, 8, 22, 14, 56, 27, 79, 23, 45, 14, 12], 0, 16), [1, 2, 4, 6, 7, 8, 8, 12, 14, 14, 22, 23, 27, 45, 56, 79])

    def test_heap_sort(self):
        self.assertEqual(heap_sort([4, 2, 6, 8, 1, 7, 8, 22, 14, 56, 27, 79, 23, 45, 14, 12]), [1, 2, 4, 6, 7, 8, 8, 12, 14, 14, 22, 23, 27, 45, 56, 79])

    def test_sort(self):
        self.assertEqual(sort([4, 2, 6, 8, 1, 7, 8, 22, 14, 56, 27, 79, 23, 45, 14, 12]), [1, 2, 4, 6, 7, 8, 8, 12, 14, 14, 22, 23, 27, 45, 56, 79])
        self.assertEqual(sort([-1, -5, -3, -13, -44]), [-44, -13, -5, -3, -1])
        self.assertEqual(sort([]), [])
        self.assertEqual(sort([5]), [5])
        self.assertEqual(sort([-3, 0, -7, 6, 23, -34]), [-34, -7, -3, 0, 6, 23])
        self.assertEqual(sort([1.7, 1.0, 3.3, 2.1, 0.3 ]), [0.3, 1.0, 1.7, 2.1, 3.3])
        self.assertEqual(sort(['d', 'a', 'b', 'e', 'c']), ['a', 'b', 'c', 'd', 'e'])

if __name__ == '__main__':
    unittest.main()