import unittest

class TestSort(unittest.TestCase):

    def test_quick_sort_3partition(self):
        test_list = [5, 4, 0, 2, 10, 7, 9, 3]
        quick_sort_3partition(test_list, 0, len(test_list) - 1)
        self.assertEqual(test_list, [0, 2, 3, 4, 5, 7, 9, 10])

    def test_quick_sort_lomuto_partition(self):
        test_list = [5, 4, 0, 2, 10, 7, 9, 3]
        quick_sort_lomuto_partition(test_list, 0, len(test_list) - 1)
        self.assertEqual(test_list, [0, 2, 3, 4, 5, 7, 9, 10])

    def test_lomuto_partition(self):
        test_list = [5, 4, 0, 2, 10, 7, 9, 3]
        pivot_index = lomuto_partition(test_list, 0, len(test_list) - 1)
        # Assert all elements less than pivot are to the left
        self.assertTrue(all(x < test_list[pivot_index] for x in test_list[:pivot_index]))
        # Assert all elements greater than pivot are to the right
        self.assertTrue(all(x > test_list[pivot_index] for x in test_list[pivot_index+1:]))

    def test_three_way_radix_quicksort(self):
        self.assertEqual(three_way_radix_quicksort([5, 4, 0, 2, 10, 7, 9, 3]), [0, 2, 3, 4, 5, 7, 9, 10])

if __name__ == "__main__":
    unittest.main()