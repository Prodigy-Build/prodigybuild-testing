import unittest

class TestGaussianElimination(unittest.TestCase):
    def test_gaussian_elimination(self):
        coefficients = [[2, 2, -1], [0, -2, -1], [0, 0, 5]]
        vector = [[5], [-7], [15]]
        result = gaussian_elimination(coefficients, vector)
        expected = [[2.], [2.], [3.]]
        self.assertTrue(np.allclose(result, expected))

if __name__ == "__main__":
    unittest.main()