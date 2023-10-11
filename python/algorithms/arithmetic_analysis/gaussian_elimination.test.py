import unittest

class TestGaussianElimination(unittest.TestCase):
    def test_retroactive_resolution(self):
        coefficients = np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]], dtype=float)
        vector = np.array([[5], [-7], [15]], dtype=float)
        result = retroactive_resolution(coefficients, vector)
        expected_result = np.array([[2.], [2.], [3.]])
        self.assertTrue(np.allclose(result, expected_result))
        
        coefficients = np.array([[2, 2], [0, -2]], dtype=float)
        vector = np.array([[-1], [-1]], dtype=float)
        result = retroactive_resolution(coefficients, vector)
        expected_result = np.array([[-1.], [0.5]])
        self.assertTrue(np.allclose(result, expected_result))
        
    def test_gaussian_elimination(self):
        coefficients = np.array([[1, -4, -2], [5, 2, -2], [1, -1, 0]], dtype=float)
        vector = np.array([[-2], [-3], [4]], dtype=float)
        result = gaussian_elimination(coefficients, vector)
        expected_result = np.array([[2.3], [-1.7], [5.55]])
        self.assertTrue(np.allclose(result, expected_result))
        
        coefficients = np.array([[1, 2], [5, 2]], dtype=float)
        vector = np.array([[5], [5]], dtype=float)
        result = gaussian_elimination(coefficients, vector)
        expected_result = np.array([[0.], [2.5]])
        self.assertTrue(np.allclose(result, expected_result))
        

unittest.main()