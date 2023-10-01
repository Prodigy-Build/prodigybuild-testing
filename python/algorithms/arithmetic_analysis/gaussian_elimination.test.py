import unittest

class TestGaussianElimination(unittest.TestCase):
    def test_retroactive_resolution(self):
        self.assertEqual(
            retroactive_resolution([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]]),
            [[2.], [2.], [3.]]
        )
        self.assertEqual(
            retroactive_resolution([[2, 2], [0, -2]], [[-1], [-1]]),
            [[-1.], [0.5]]
        )

    def test_gaussian_elimination(self):
        self.assertEqual(
            gaussian_elimination([[1, -4, -2], [5, 2, -2], [1, -1, 0]], [[-2], [-3], [4]]),
            [[2.3], [-1.7], [5.55]]
        )
        self.assertEqual(
            gaussian_elimination([[1, 2], [5, 2]], [[5], [5]]),
            [[0.], [2.5]]
        )

if __name__ == '__main__':
    unittest.main()