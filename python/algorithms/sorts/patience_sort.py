import unittest

class TestPatienceSort(unittest.TestCase):
    def test_sort(self):
        self.assertEqual(patience_sort([1, 9, 5, 21, 17, 6]), [1, 5, 6, 9, 17, 21])
        self.assertEqual(patience_sort([]), [])
        self.assertEqual(patience_sort([-3, -17, -48]), [-48, -17, -3])
        self.assertEqual(patience_sort([1]), [1])
        self.assertEqual(patience_sort([1,5,6,6,9,9]), [1,5,6,6,9,9])

if __name__ == "__main__":
    unittest.main()