import unittest

class TestGaussianElimination(unittest.TestCase):

    def test_gaussian_elimination(self):
        result = gaussian_elimination([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]])
        self.assertAlmostEqual(result[0][0], 2.0)
        self.assertAlmostEqual(result[1][0], 2.0)
        self.assertAlmostEqual(result[2][0], 3.0)

        result = gaussian_elimination([[2, 2], [0, -2]], [[-1], [-1]])
        self.assertAlmostEqual(result[0][0], -1.0)
        self.assertAlmostEqual(result[1][0], 0.5)

unittest.main()