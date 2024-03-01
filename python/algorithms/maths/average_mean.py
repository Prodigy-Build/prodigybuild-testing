from typing import List
import unittest

def mean(nums: List[int]) -> float:
    if not nums:
        raise ValueError("List is empty")
    return sum(nums) / len(nums)

class TestMean(unittest.TestCase):
    def test_mean(self):
        self.assertEqual(mean([3, 6, 9, 12, 15, 18, 21]), 12.0)
        self.assertEqual(mean([5, 10, 15, 20, 25, 30, 35]), 20.0)
        self.assertEqual(mean([1, 2, 3, 4, 5, 6, 7, 8]), 4.5)
        with self.assertRaises(ValueError):
            mean([])

if __name__ == "__main__":
    unittest.main()