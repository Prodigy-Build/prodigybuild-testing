import unittest

class TestDoubleSort(unittest.TestCase):

    def test_double_sort(self):
        self.assertEqual(double_sort([-1, -2, -3, -4, -5, -6, -7]), [-7, -6, -5, -4, -3, -2, -1])
        self.assertEqual(double_sort([]), [])
        self.assertEqual(double_sort([-1, -2, -3, -4, -5, -6]), [-6, -5, -4, -3, -2, -1])
        self.assertEqual(double_sort([-3, 10, 16, -42, 29]), sorted([-3, 10, 16, -42, 29]))
        
        # Add a few more edge cases
        self.assertEqual(double_sort([0]), [0])
        self.assertEqual(double_sort([1, 0]), [0, 1])
        self.assertEqual(double_sort([0, -1]), [-1, 0])

if __name__ == '__main__':
    unittest.main()