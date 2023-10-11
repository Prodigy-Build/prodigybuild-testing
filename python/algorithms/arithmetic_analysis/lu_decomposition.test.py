import unittest

class TestLUDecomposition(unittest.TestCase):

    def test_lower_upper_decomposition(self):
        matrix = np.array([[2, -2, 1], [0, 1, 2], [5, 3, 1]])
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
        np.testing.assert_array_equal(lower_mat, np.array([[1. , 0. , 0. ],
                                                           [0. , 1. , 0. ],
                                                           [2.5, 8. , 1. ]]))
        np.testing.assert_array_equal(upper_mat, np.array([[  2. ,  -2. ,   1. ],
                                                           [  0. ,   1. ,   2. ],
                                                           [  0. ,   0. , -17.5]]))

        matrix = np.array([[4, 3], [6, 3]])
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
        np.testing.assert_array_equal(lower_mat, np.array([[1. , 0. ],
                                                           [1.5, 1. ]]))
        np.testing.assert_array_equal(upper_mat, np.array([[ 4. ,  3. ],
                                                           [ 0. , -1.5]]))

        matrix = np.array([[2, -2, 1], [0, 1, 2]])
        with self.assertRaises(ValueError):
            lower_mat, upper_mat = lower_upper_decomposition(matrix)

        matrix = np.array([[0, 1], [1, 0]])
        with self.assertRaises(ArithmeticError):
            lower_mat, upper_mat = lower_upper_decomposition(matrix)

        matrix = np.array([[1, 0], [1, 0]])
        np.testing.assert_array_equal(lower_mat, np.array([[1., 0.],
                                                           [1., 1.]]))
        np.testing.assert_array_equal(upper_mat, np.array([[1., 0.],
                                                           [0., 0.]]))

        matrix = np.array([[0, 1], [0, 1]])
        with self.assertRaises(ArithmeticError):
            lower_mat, upper_mat = lower_upper_decomposition(matrix)

if __name__ == "__main__":
    unittest.main()