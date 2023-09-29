import unittest
import numpy as np

class LUdecompositionTestCase(unittest.TestCase):
    def test_LUdecomposition(self):
        matrix = np.array([[2, -2, 1], [0, 1, 2], [5, 3, 1]])
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
        np.testing.assert_array_equal(lower_mat, np.array([[1. , 0. , 0. ],[0. , 1. , 0. ],[2.5, 8. , 1. ]]))
        np.testing.assert_array_equal(upper_mat, np.array([[  2. ,  -2. ,   1. ],[  0. ,   1. ,   2. ],[  0. ,   0. , -17.5]]))

        matrix = np.array([[4, 3], [6, 3]])
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
        np.testing.assert_array_equal(lower_mat, np.array([[1., 0.],[1.5, 1.]]))
        np.testing.assert_array_equal(upper_mat, np.array([[ 4. ,  3. ],[ 0. , -1.5]]))

        matrix = np.array([[2, -2, 1], [0, 1, 2]])
        with self.assertRaises(ValueError):
            lower_upper_decomposition(matrix)

        matrix = np.array([[0, 1], [1, 0]])
        with self.assertRaises(ArithmeticError):
            lower_upper_decomposition(matrix)

        matrix = np.array([[1, 0], [1, 0]])
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
        np.testing.assert_array_equal(lower_mat, np.array([[1., 0.],[1., 1.]]))
        np.testing.assert_array_equal(upper_mat, np.array([[1., 0.],[0., 0.]]))

        matrix = np.array([[0, 1], [0, 1]])
        with self.assertRaises(ArithmeticError):
            lower_upper_decomposition(matrix)

unittest.main()