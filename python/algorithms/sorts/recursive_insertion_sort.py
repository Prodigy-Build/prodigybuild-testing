import unittest

class TestRecursiveInsertionSort(unittest.TestCase):
    def test_empty_list(self):
        arr = []
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [])

    def test_single_element(self):
        arr = [1]
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [1])

    def test_two_elements(self):
        arr = [2, 1]
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [1, 2])

    def test_multiple_elements(self):
        arr = [4, 3, 2, 1]
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [1, 2, 3, 4])

    def test_negative_elements(self):
        arr = [-1, -2, -3, -4]
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [-4, -3, -2, -1])

    def test_mixed_elements(self):
        arr = [4, -3, 2, -1]
        rec_insertion_sort(arr, len(arr))
        self.assertEqual(arr, [-3, -1, 2, 4])


if __name__ == "__main__":
    unittest.main()