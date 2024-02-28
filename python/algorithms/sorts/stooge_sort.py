import unittest

class TestStoogeSort(unittest.TestCase):

    def test_sort1(self):
        arr = [18.1, 0, -7.1, -1, 2, 2]
        result = stooge_sort(arr)
        self.assertEqual(result, [-7.1, -1, 0, 2, 2, 18.1])

    def test_sort2(self):
        arr = [5, 2, 8, 3, 1, 9]
        result = stooge_sort(arr)
        self.assertEqual(result, [1, 2, 3, 5, 8, 9])

    def test_empty(self):
        arr = []
        result = stooge_sort(arr)
        self.assertEqual(result, [])


if __name__ == '__main__':
    unittest.main()