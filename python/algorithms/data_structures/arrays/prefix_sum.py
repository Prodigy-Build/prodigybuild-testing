import unittest

class TestPrefixSum(unittest.TestCase):
    def setUp(self):
        self.ps1 = PrefixSum([1, 2, 3, 4, 5])
        self.ps2 = PrefixSum([5, -3, 2])
        self.ps3 = PrefixSum([])
        self.ps4 = PrefixSum([-1, -2, -3])
        self.ps5 = PrefixSum([7])

    def test_get_sum(self):
        self.assertEqual(self.ps1.get_sum(0, 2), 6)
        self.assertEqual(self.ps1.get_sum(1, 3), 9)
        self.assertEqual(self.ps2.get_sum(0, 2), 4)
        with self.assertRaises(IndexError):
            self.ps3.get_sum(0,0)
        self.assertEqual(self.ps4.get_sum(0, 2), -6)
        self.assertEqual(self.ps5.get_sum(0, 0), 7)

    def test_contains_sum(self):
        self.assertEqual(self.ps1.contains_sum(6), True)
        self.assertEqual(self.ps1.contains_sum(10), True)
        self.assertEqual(self.ps2.contains_sum(4), True)
        self.assertEqual(self.ps3.contains_sum(0), False)
        self.assertEqual(self.ps4.contains_sum(-3), True)
        self.assertEqual(self.ps5.contains_sum(7), True)


if __name__ == '__main__':
    unittest.main()