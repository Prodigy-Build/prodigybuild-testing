```python
import unittest
import numpy as np

class TestGaussianElimination(unittest.TestCase):

    def test_retroactive_resolution(self):
        coefficients = np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]])
        vector = np.array([[5], [-7], [15]])
        result = retroactive_resolution(coefficients, vector)
        expected = np.array([[2.], [2.], [3.]])
        np.testing.assert_array_equal(result, expected)

    def test_gaussian_elimination(self):
        coefficients = np.array([[1, -4, -2], [5, 2, -2], [1, -1, 0]])
        vector = np.array([[-2], [-3], [4]])
        result = gaussian_elimination(coefficients, vector)
        expected = np.array([[2.3], [-1.7], [5.55]])
        np.testing.assert_array_almost_equal(result, expected, decimal=2)

        coefficients = np.array([[1, 2], [5, 2]])
        vector = np.array([[5], [5]])
        result = gaussian_elimination(coefficients, vector)
        expected = np.array([[0.], [2.5]])
        np.testing.assert_array_almost_equal(result, expected, decimal=2)

if __name__ == '__main__':
    unittest.main()
```