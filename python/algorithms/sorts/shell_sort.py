import unittest

class TestShellSort(unittest.TestCase):
    def test_shell_sort(self):
        self.assertEqual(shell_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(shell_sort([]), [])
        self.assertEqual(shell_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(shell_sort([10, -2, 8, 6, -7, 8]), [-7, -2, 6, 8, 8, 10])

    def test_shell_sort_unordered(self):
        self.assertEqual(shell_sort([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

    def test_shell_sort_ordered(self):
        self.assertEqual(shell_sort([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

if __name__ == "__main__":
    unittest.main()