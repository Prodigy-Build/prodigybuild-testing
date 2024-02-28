import unittest

class TestRadixSort(unittest.TestCase):
    def test_sort(self):
        self.assertEqual(radix_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(radix_sort(list(range(15))), sorted(range(15)))
        self.assertEqual(radix_sort(list(range(14,-1,-1))), sorted(range(15)))
        self.assertEqual(radix_sort([1,100,10,1000]), sorted([1,100,10,1000]))

    def test_empty_list(self):
        self.assertEqual(radix_sort([]), [])

    def test_single_element_list(self):
        self.assertEqual(radix_sort([10]), [10])

    def test_negative_numbers(self):
        self.assertEqual(radix_sort([-3, -1, -2]), sorted([-3, -1, -2]))


if __name__ == "__main__":
    unittest.main()