import unittest

class TestMergeSort(unittest.TestCase):

    def test_sort(self):
        self.assertEqual(merge([10,9,8,7,6,5,4,3,2,1]), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
        self.assertEqual(merge([1,2,3,4,5,6,7,8,9,10]), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
        self.assertEqual(merge([10,22,1,2,3,9,15,23]), [1, 2, 3, 9, 10, 15, 22, 23])
        self.assertEqual(merge([100]), [100])
        self.assertEqual(merge([]), [])

if __name__ == "__main__":
    unittest.main()