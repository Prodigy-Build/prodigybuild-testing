import unittest

class TestCountingSort(unittest.TestCase):

    def test_counting_sort(self):
        self.assertEqual(counting_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(counting_sort([]), [])
        self.assertEqual(counting_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(counting_sort([1]), [1])
        self.assertEqual(counting_sort([2, 1]), [1, 2])

    def test_counting_sort_string(self):
        self.assertEqual(counting_sort_string("thisisthestring"), "eghhiiinrsssttt")
        self.assertEqual(counting_sort_string(""), "")
        self.assertEqual(counting_sort_string("a"), "a")
        self.assertEqual(counting_sort_string("ba"), "ab")

if __name__ == "__main__":
    unittest.main()