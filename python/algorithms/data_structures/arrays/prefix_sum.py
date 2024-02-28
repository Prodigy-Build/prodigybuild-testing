import unittest

class TestPrefixSum(unittest.TestCase):
    def test_get_sum(self):
        prefix_sum = PrefixSum([1, 2, 3])
        self.assertEqual(prefix_sum.get_sum(0, 2), 6)
        self.assertEqual(prefix_sum.get_sum(1, 2), 5)
        self.assertEqual(prefix_sum.get_sum(2, 2), 3)
        self.assertRaises(IndexError, prefix_sum.get_sum, 2, 3)

    def test_contains_sum(self):
        prefix_sum = PrefixSum([1, 2, 3])
        self.assertTrue(prefix_sum.contains_sum(6))
        self.assertTrue(prefix_sum.contains_sum(5))
        self.assertTrue(prefix_sum.contains_sum(3))
        self.assertFalse(prefix_sum.contains_sum(4))
        self.assertFalse(prefix_sum.contains_sum(7))
        prefix_sum = PrefixSum([1, -2, 3])
        self.assertTrue(prefix_sum.contains_sum(2))

if __name__ == "__main__":
    unittest.main()