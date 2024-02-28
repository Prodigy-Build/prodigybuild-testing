import unittest

class TestTimSort(unittest.TestCase):
    def test_binary_search(self):
        self.assertEqual(binary_search([1, 2, 3], 2, 0, 2), 1)
        self.assertEqual(binary_search([1, 2, 3], 4, 0, 2), 3)

    def test_insertion_sort(self):
        self.assertEqual(insertion_sort([4, 3, 2, 1]), [1, 2, 3, 4])
        self.assertEqual(insertion_sort([1]), [1])

    def test_merge(self):
        self.assertEqual(merge([1, 3], [2, 4]), [1, 2, 3, 4])
        self.assertEqual(merge([], [2, 4]), [2, 4])
        self.assertEqual(merge([1, 3], []), [1, 3])

    def test_tim_sort(self):
        self.assertEqual(tim_sort([4, 3, 2, 1]), [1, 2, 3, 4])
        self.assertEqual(tim_sort([1]), [1])
        self.assertEqual(tim_sort("Python"), ['P', 'h', 'n', 'o', 't', 'y'])
        self.assertEqual(tim_sort((1.1, 1, 0, -1, -1.1)), [-1.1, -1, 0, 1, 1.1])
        self.assertEqual(tim_sort(list(reversed(list(range(7))))), [0, 1, 2, 3, 4, 5, 6])

if __name__ == "__main__":
    unittest.main()