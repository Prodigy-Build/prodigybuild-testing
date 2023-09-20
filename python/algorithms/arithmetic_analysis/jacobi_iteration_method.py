"""
Jacobi Iteration Method - https://en.wikipedia.org/wiki/Jacobi_method
"""

import numpy as np
from numpy.typing import NDArray
from typing import List

# Method to find solution of system of linear equations
def jacobi_iteration_method(
    coefficient_matrix: NDArray[np.float64],
    constant_matrix: NDArray[np.float64],
    init_val: List[float],
    iterations: int,
) -> List[float]:

    rows1, cols1 = coefficient_matrix.shape
    rows2, cols2 = constant_matrix.shape

    if rows1 != cols1:
        msg = f"Coefficient matrix dimensions must be nxn but received {rows1}x{cols1}"
        raise ValueError(msg)

    if cols2 != 1:
        msg = f"Constant matrix must be nx1 but received {rows2}x{cols2}"
        raise ValueError(msg)

    if rows1 != rows2:
        msg = (
            "Coefficient and constant matrices dimensions must be nxn and nx1 but "
            f"received {rows1}x{cols1} and {rows2}x{cols2}"
        )
        raise ValueError(msg)

    if len(init_val) != rows1:
        msg = (
            "Number of initial values must be equal to number of rows in coefficient "
            f"matrix but received {len(init_val)} and {rows1}"
        )
        raise ValueError(msg)

    if iterations <= 0:
        raise ValueError("Iterations must be at least 1")

    table: NDArray[np.float64] = np.concatenate(
        (coefficient_matrix, constant_matrix), axis=1
    )

    rows, cols = table.shape

    strictly_diagonally_dominant(table)

    # Iterates the whole matrix for given number of times
    for _ in range(iterations):
        new_val = []
        for row in range(rows):
            temp = 0
            for col in range(cols):
                if col == row:
                    denom = table[row][col]
                elif col == cols - 1:
                    val = table[row][col]
                else:
                    temp += (-1) * table[row][col] * init_val[col]
            temp = (temp + val) / denom
            new_val.append(temp)
        init_val = new_val

    return [float(i) for i in new_val]


# Checks if the given matrix is strictly diagonally dominant
def strictly_diagonally_dominant(table: NDArray[np.float64]) -> bool:

    rows, cols = table.shape

    is_diagonally_dominant = True

    for i in range(rows):
        total = 0
        for j in range(cols - 1):
            if i != j:
                total += abs(table[i][j])
        if abs(table[i][i]) < total:
            is_diagonally_dominant = False
            raise ValueError("The matrix is not strictly diagonally dominant")

    return is_diagonally_dominant


# Test Cases
if __name__ == "__main__":
    import doctest
    doctest.testmod()