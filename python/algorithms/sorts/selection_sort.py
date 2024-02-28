import unittest

class TestSelectionSort(unittest.TestCase):

    def test_empty_list(self):
        self.assertEqual(selection_sort([]), [])

    def test_sorts_in_ascending_order(self):
        self.assertEqual(selection_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])

    def test_sorts_negative_numbers(self):
        self.assertEqual(selection_sort([-2, -5, -45]), [-45, -5, -2])

    def test_sorts_mixed_positive_and_negative_numbers(self):
        self.assertEqual(selection_sort([-2, -5, 0, 5, 3, 2, 2, -45]), [-45, -5, -2, 0, 2, 2, 3, 5])

if __name__ == "__main__":
    unittest.main()