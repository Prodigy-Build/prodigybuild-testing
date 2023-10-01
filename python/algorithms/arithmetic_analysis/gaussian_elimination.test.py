import unittest

class TestGaussianElimination(unittest.TestCase):

    def test_gaussian_elimination_1(self):
        coefficients = [[2, 2, -1], [0, -2, -1], [0, 0, 5]]
        vector = [[5], [-7], [15]]
        result = gaussian_elimination(coefficients, vector)
        expected_result = np.array([[2.], [2.], [3.]])
        np.testing.assert_array_equal(result, expected_result)

    def test_gaussian_elimination_2(self):
        coefficients = [[2, 2], [0, -2]]
        vector = [[-1], [-1]]
        result = gaussian_elimination(coefficients, vector)
        expected_result = np.array([[-1.], [0.5]])
        np.testing.assert_array_equal(result, expected_result)

if __name__ == '__main__':
    unittest.main()