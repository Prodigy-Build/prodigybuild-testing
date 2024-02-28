import unittest

class TestIterMergeSort(unittest.TestCase):

    def test_sorted_numbers(self):
        self.assertEqual(iter_merge_sort([5, 9, 8, 7, 1, 2, 7]), [1, 2, 5, 7, 7, 8, 9])

    def test_single_element(self):
        self.assertEqual(iter_merge_sort([1]), [1])

    def test_two_elements(self):
        self.assertEqual(iter_merge_sort([2, 1]), [1, 2])

    def test_three_elements(self):
        self.assertEqual(iter_merge_sort([2, 1, 3]), [1, 2, 3])

    def test_descending_order(self):
        self.assertEqual(iter_merge_sort([4, 3, 2, 1]), [1, 2, 3, 4])

    def test_alphabet_sort(self):
        self.assertEquals(iter_merge_sort(['c', 'b', 'a']), ['a', 'b', 'c'])

    def test_negative_numbers_sort(self):
        self.assertEqual(iter_merge_sort([-2, -9, -1, -4]), [-9, -4, -2, -1])

    def test_float_sort(self):
        self.assertEqual(iter_merge_sort([1.1, 1, 0.0, -1, -1.1]), [-1.1, -1, 0.0, 1, 1.1]) 

    def test_string_sort(self):
        self.assertEqual(iter_merge_sort('cba'), ['a', 'b', 'c'])

if __name__ == '__main__':
    unittest.main()