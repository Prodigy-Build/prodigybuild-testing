import numpy as np
import unittest


class TestGaussianElimination(unittest.TestCase):
    def test_retroactive_resolution(self):
        coeff = np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]], dtype=float)
        vector = np.array([[5], [-7], [15]], dtype=float)
        result = retroactive_resolution(coeff, vector)
        expected = np.array([[2.], [2.], [3.]])
        np.testing.assert_allclose(result, expected)

        coeff = np.array([[2, 2], [0, -2]], dtype=float)
        vector = np.array([[-1], [-1]], dtype=float)
        result = retroactive_resolution(coeff, vector)
        expected = np.array([[-1.], [0.5]])
        np.testing.assert_allclose(result, expected)

    def test_gaussian_elimination(self):
        coeff = np.array([[1, -4, -2], [5, 2, -2], [1, -1, 0]], dtype=float)
        vector = np.array([[-2], [-3], [4]], dtype=float)
        result = gaussian_elimination(coeff, vector)
        expected = np.array([[2.3], [-1.7], [5.55]])
        np.testing.assert_allclose(result, expected)

        coeff = np.array([[1, 2], [5, 2]], dtype=float)
        vector = np.array([[5], [5]], dtype=float)
        result = gaussian_elimination(coeff, vector)
        expected = np.array([[0.], [2.5]])
        np.testing.assert_allclose(result, expected)


if __name__ == "__main__":
    unittest.main()