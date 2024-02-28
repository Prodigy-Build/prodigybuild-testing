import unittest

class TestShellSort(unittest.TestCase):
    def test_shell_sort(self):
        self.assertEqual(shell_sort([3, 2, 1]), [1, 2, 3])
        self.assertEqual(shell_sort([]), [])
        self.assertEqual(shell_sort([1]), [1])
        self.assertEqual(shell_sort([-3, -1, -2]), [-3, -2, -1])
        self.assertEqual(shell_sort([3, 2, 2]), [2, 2, 3])
        self.assertEqual(shell_sort([3, 2, 2, 1, 1, 1]), [1, 1, 1, 2, 2, 3])

if __name__ == '__main__':
    unittest.main()