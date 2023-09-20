"""
Lower–upper (LU) decomposition factors a matrix as a product of a lower
triangular matrix and an upper triangular matrix. A square matrix has an LU
decomposition under the following conditions:
    - If the matrix is invertible, then it has an LU decomposition if and only
    if all of its leading principal minors are non-zero (see
    https://en.wikipedia.org/wiki/Minor_(linear_algebra) for an explanation of
    leading principal minors of a matrix).
    - If the matrix is singular (i.e., not invertible) and it has a rank of k
    (i.e., it has k linearly independent columns), then it has an LU
    decomposition if its first k leading principal minors are non-zero.

This algorithm will simply attempt to perform LU decomposition on any square
matrix and raise an error if no such decomposition exists.

Reference: https://en.wikipedia.org/wiki/LU_decomposition
"""
import numpy as np
from typing import Tuple

def lower_upper_decomposition(table: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:
    """
    Perform LU decomposition on a given matrix and raises an error if the matrix
    isn't square or if no such decomposition exists
    """
    # Ensure that table is a square array
    rows, columns = np.shape(table)
    if rows != columns:
        msg = (
            "'table' has to be of square shaped array but got a "
            f"{rows}x{columns} array:\n{table}"
        )
        raise ValueError(msg)

    lower = np.zeros((rows, columns))
    upper = np.zeros((rows, columns))
    for i in range(columns):
        for j in range(i):
            total = sum(lower[i][k] * upper[k][j] for k in range(j))
            if upper[j][j] == 0:
                raise ArithmeticError("No LU decomposition exists")
            lower[i][j] = (table[i][j] - total) / upper[j][j]
        lower[i][i] = 1
        for j in range(i, columns):
            total = sum(lower[i][k] * upper[k][j] for k in range(i))
            upper[i][j] = table[i][j] - total
    return lower, upper


if __name__ == "__main__":
    import doctest

    doctest.testmod()