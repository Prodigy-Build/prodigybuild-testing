import unittest


class GaussianEliminationTestCase(unittest.TestCase):
    def test_gaussian_elimination_1(self):
        coefficients = [[2, 2, -1], [0, -2, -1], [0, 0, 5]]
        vector = [[5], [-7], [15]]
        expected_result = [[2.],[2.],[3.]]
        result = gaussian_elimination(coefficients, vector)
        self.assertEqual(result.tolist(), expected_result)

    def test_gaussian_elimination_2(self):
        coefficients = [[2, 2], [0, -2]]
        vector = [[-1], [-1]]
        expected_result = [[-1.],[0.5]]
        result = gaussian_elimination(coefficients, vector)
        self.assertEqual(result.tolist(), expected_result)


if __name__ == '__main__':
    unittest.main()