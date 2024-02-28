import unittest

class TestQuickSort(unittest.TestCase):

    def test_quick_sort(self):
        data = [6, 2, 7, 4, 1, 3, 5]
        result = quick_sort(data)
        self.assertEqual(result, [1, 2, 3, 4, 5, 6, 7])

    def test_quick_sort_empty(self):
        data = []
        result = quick_sort(data)
        self.assertEqual(result, [])

    def test_quick_sort_one_element(self):
        data = [1]
        result = quick_sort(data)
        self.assertEqual(result, [1])

    def test_quick_sort_negative_numbers(self):
        data = [-2, -5, -1]
        result = quick_sort(data)
        self.assertEqual(result, [-5, -2, -1])

if __name__ == '__main__':
    unittest.main()