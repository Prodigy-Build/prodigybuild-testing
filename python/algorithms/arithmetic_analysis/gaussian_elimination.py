```python
import unittest
import numpy as np
from numpy import float64
from numpy.typing import NDArray
from arithmetic_analysis import gaussian_elimination, retroactive_resolution

class GaussianEliminationTest(unittest.TestCase):

    def test_gaussian_elimination(self):
        coefficients = np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]])
        vector = np.array([[5], [-7], [15]])
        expected = np.array([[2.], [2.], [3.]])
        result = gaussian_elimination(coefficients, vector)
        self.assertTrue(np.allclose(result, expected))

    def test_retroactive_resolution(self):
        coefficients = np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]])
        vector = np.array([[5], [-7], [15]])
        expected = np.array([[2.], [2.], [3.]])
        result = retroactive_resolution(coefficients, vector)
        self.assertTrue(np.allclose(result, expected))

if __name__ == '__main__':
    unittest.main()
```