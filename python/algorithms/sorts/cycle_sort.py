import unittest

class TestCycleSort(unittest.TestCase):

    def test_cycle_sort(self):
        self.assertEqual(cycle_sort([4, 3, 2, 1]), [1, 2, 3, 4])
        self.assertEqual(cycle_sort([-4, 20, 0, -50, 100, -1]), [-50, -4, -1, 0, 20, 100])
        self.assertEqual(cycle_sort([-.1, -.2, 1.3, -.8]), [-0.8, -0.2, -0.1, 1.3])
        self.assertEqual(cycle_sort([]), [])
        
    def test_cycle_sort_asserts(self):
        self.assertTrue(cycle_sort([4, 5, 3, 2, 1]) == [1, 2, 3, 4, 5])
        self.assertTrue(cycle_sort([0, 1, -10, 15, 2, -2]) == [-10, -2, 0, 1, 2, 15])

if __name__ == '__main__':
    unittest.main()