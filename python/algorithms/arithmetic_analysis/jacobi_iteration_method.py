import numpy as np
from numpy.typing import NDArray
from numpy.linalg import inv


def jacobi_iteration_method(
    coefficient_matrix: NDArray[float64], 
    constant_matrix: NDArray[float64], 
    init_val: NDArray[float64], 
    iterations: int
) -> NDArray[float64]:
   
    rows, cols = coefficient_matrix.shape
    new_val = np.zeros(cols)
    for _ in range(iterations):
        for i in range(rows):
            sum_val = constant_matrix[i]
            for j in range(cols):
                if j != i:
                    sum_val -= coefficient_matrix[i][j] * init_val[j]
            new_val[i] = sum_val / coefficient_matrix[i][i]
        init_val = new_val.copy()
    return new_val


if __name__ == "__main__":
    coefficient_matrix = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant_matrix = np.array([[2], [-6], [-4]])
    init_val = np.array([0.5, -0.5, -0.5])
    iterations = 3
    result = jacobi_iteration_method(coefficient_matrix, constant_matrix, init_val, iterations)
    print(result)