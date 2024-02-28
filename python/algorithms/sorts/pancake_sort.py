import unittest


class TestPancakeSort(unittest.TestCase):
    def test_pancake_sort(self):
        self.assertEqual(pancake_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(pancake_sort([]), [])
        self.assertEqual(pancake_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(pancake_sort([1, 1, 1, 1, 1]), [1, 1, 1, 1, 1])
        self.assertEqual(pancake_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
    

if __name__ == "__main__":
    unittest.main()