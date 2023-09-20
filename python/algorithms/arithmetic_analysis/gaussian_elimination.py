"""
Updated Python code:

Gaussian elimination method for solving a system of linear equations.
Gaussian elimination - https://en.wikipedia.org/wiki/Gaussian_elimination
"""


import numpy as np
from numpy import float64
from numpy.typing import NDArray


def retroactive_resolution(
    coefficients: NDArray[float64], vector: NDArray[float64]
) -> NDArray[float64]:
    rows, columns = np.shape(coefficients)

    x: NDArray[float64] = np.zeros((rows, 1), dtype=float)
    for row in reversed(range(rows)):
        total = 0
        for col in range(row + 1, columns):
            total += coefficients[row, col] * x[col]

        x[row, 0] = (vector[row] - total) / coefficients[row, row]

    return x


def gaussian_elimination(
    coefficients: NDArray[float64], vector: NDArray[float64]
) -> NDArray[float64]:
    rows, columns = np.shape(coefficients)
    if rows != columns:
        return np.array((), dtype=float)

    augmented_mat: NDArray[float64] = np.concatenate((coefficients, vector), axis=1)
    augmented_mat = augmented_mat.astype("float64")

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