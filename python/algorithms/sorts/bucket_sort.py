import unittest
from bucket_sort import bucket_sort

class TestBucketSort(unittest.TestCase):
    def test_bucket_sort(self):
        self.assertEqual(bucket_sort([4, 5, 3, 2, 1]), [1, 2, 3, 4, 5])
        self.assertEqual(bucket_sort([0, 1, -10, 15, 2, -2]), [-10, -2, 0, 1, 2, 15])
        self.assertEqual(bucket_sort([-1, 2, -5, 0]), [-5, -1, 0, 2])
        self.assertEqual(bucket_sort([9, 8, 7, 6, -12]), [-12, 6, 7, 8, 9])
        self.assertEqual(bucket_sort([.4, 1.2, .1, .2, -.9]), [-.9, .1, .2, .4, 1.2])
        self.assertEqual(bucket_sort([]), [])

if __name__ == "__main__":
    unittest.main()