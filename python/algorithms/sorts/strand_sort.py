import unittest

class TestStrandSort(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(strand_sort([4, 3, 5, 1, 2]), [1, 2, 3, 4, 5])

    def test_reverse(self):
        self.assertEqual(strand_sort([4, 3, 5, 1, 2], reverse=True), [5, 4, 3, 2, 1])

    def test_empty(self):
        self.assertEqual(strand_sort([]), [])

    def test_single_element(self):
        self.assertEqual(strand_sort([1]), [1])

    def test_duplicate_elements(self):
        self.assertEqual(strand_sort([1, 1, 1, 1]), [1, 1, 1, 1])

    def test_negative_elements(self):
        self.assertEqual(strand_sort([-1, -5, -3, -4]), [-5, -4, -3, -1])

if __name__ == "__main__":
    unittest.main()