 # Jacobi Iteration Method -  Write unit tests

def test_jacobi_iteration_method():
    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    assert jacobi_iteration_method(coefficient, constant, init_val, iterations) == [0.909375, -1.14375, -0.7484375]

    coefficient = np.array([[4, 1, 1], [1, 5, 2]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
        assert False
    except ValueError:
        assert True

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
        assert False
    except ValueError:
        assert True

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5]
    iterations = 3
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
        assert False
    except ValueError:
        assert True

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 0
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
        assert False
    except ValueError:
        assert True