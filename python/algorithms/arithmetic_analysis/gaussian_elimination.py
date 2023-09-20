"""
Gaussian elimination method for solving a system of linear equations.
Gaussian elimination - https://en.wikipedia.org/wiki/Gaussian_elimination
"""

from typing import Any, Tuple, Union
import numpy as np


def retroactive_resolution(coefficients: np.ndarray, vector: np.ndarray) -> np.ndarray:
    """
    This function performs a retroactive linear system resolution
        for triangular matrix
    """
    rows, columns = np.shape(coefficients)

    x: np.ndarray = np.zeros((rows, 1), dtype=float)
    for row in reversed(range(rows)):
        total = 0
        for col in range(row + 1, columns):
            total += coefficients[row, col] * x[col]

        x[row, 0] = (vector[row] - total) / coefficients[row, row]

    return x


def gaussian_elimination(coefficients: np.ndarray, vector: np.ndarray) -> np.ndarray:
    """
    This function performs Gaussian elimination method
    """
    # coefficients must to be a square matrix so we need to check first
    rows, columns = np.shape(coefficients)
    if rows != columns:
        return np.array((), dtype=float)

    # augmented matrix
    augmented_mat: np.ndarray = np.concatenate((coefficients, vector), axis=1)
    augmented_mat = augmented_mat.astype("float64")

    # scale the matrix leaving it triangular
    for row in range(rows - 1):
        pivot = augmented_mat[row, row]
        for col in range(row + 1, columns):
            factor = augmented_mat[col, row] / pivot
            augmented_mat[col, :] -= factor * augmented_mat[row, :]

    x = retroactive_resolution(
        augmented_mat[:, 0:columns], augmented_mat[:, columns : columns + 1]
    )

    return x


if __name__ == "__main__":
    import doctest
    doctest.testmod()