from typing import List
import numpy as np

def test_jacobi_iteration_method():
    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    output = jacobi_iteration_method(coefficient, constant, init_val, iterations)
    assert output == [0.909375, -1.14375, -0.7484375]

    coefficient = np.array([[4, 1, 1], [1, 5, 2]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    try:
        output = jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError as e:
        assert str(e) == "Coefficient matrix dimensions must be nxn but received 2x3"

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    try:
        output = jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError as e:
        assert str(e) == "Coefficient and constant matrices dimensions must be nxn and nx1 but received 3x3 and 2x1"

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5]
    iterations = 3
    try:
        output = jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError as e:
        assert str(e) == "Number of initial values must be equal to number of rows in coefficient matrix but received 2 and 3"

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 0
    try:
        output = jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError as e:
        assert str(e) == "Iterations must be at least 1"

test_jacobi_iteration_method()