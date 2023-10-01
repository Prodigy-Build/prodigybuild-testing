"""
import numpy as np

def test_lower_upper_decomposition():
    matrix = np.array([[2, -2, 1], [0, 1, 2], [5, 3, 1]])
    lower_mat, upper_mat = lower_upper_decomposition(matrix)
    assert np.allclose(lower_mat, np.array([[1. , 0. , 0. ], [0. , 1. , 0. ], [2.5, 8. , 1. ]])))
    assert np.allclose(upper_mat, np.array([[  2. ,  -2. ,   1. ], [  0. ,   1. ,   2. ], [  0. ,   0. , -17.5]])))

    matrix = np.array([[4, 3], [6, 3]])
    lower_mat, upper_mat = lower_upper_decomposition(matrix)
    assert np.allclose(lower_mat, np.array([[1. , 0. ], [1.5, 1. ]])))
    assert np.allclose(upper_mat, np.array([[ 4. ,  3. ], [ 0. , -1.5]])))

    matrix = np.array([[2, -2, 1], [0, 1, 2]])
    try:
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
    except ValueError as e:
        assert str(e) == "'table' has to be of square shaped array but got a 2x3 array:\n[[ 2 -2  1]\n [ 0  1  2]]"

    matrix = np.array([[0, 1], [1, 0]])
    try:
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
    except ArithmeticError as e:
        assert str(e) == "No LU decomposition exists"

    matrix = np.array([[1, 0], [1, 0]])
    assert np.allclose(lower_mat, np.array([[1., 0.], [1., 1. ]])))
    assert np.allclose(upper_mat, np.array([[1., 0.], [0., 0. ]])))

    matrix = np.array([[0, 1], [0, 1]])
    try:
        lower_mat, upper_mat = lower_upper_decomposition(matrix)
    except ArithmeticError as e:
        assert str(e) == "No LU decomposition exists"

test_lower_upper_decomposition()
"""