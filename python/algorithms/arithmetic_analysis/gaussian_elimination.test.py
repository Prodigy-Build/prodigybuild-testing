import unittest

class TestGaussianElimination(unittest.TestCase):

    def test_retroactive_resolution(self):
        result = retroactive_resolution([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]])
        expected = np.array([[2.], [2.], [3.]])
        np.testing.assert_array_equal(result, expected)

        result = retroactive_resolution([[2, 2], [0, -2]], [[-1], [-1]])
        expected = np.array([[-1.], [0.5]])
        np.testing.assert_array_equal(result, expected)

    def test_gaussian_elimination(self):
        result = gaussian_elimination([[1, -4, -2], [5, 2, -2], [1, -1, 0]], [[-2], [-3], [4]])
        expected = np.array([[2.3], [-1.7], [5.55]])
        np.testing.assert_array_equal(result, expected)

        result = gaussian_elimination([[1, 2], [5, 2]], [[5], [5]])
        expected = np.array([[0.], [2.5]])
        np.testing.assert_array_equal(result, expected)

if __name__ == "__main__":
    unittest.main()