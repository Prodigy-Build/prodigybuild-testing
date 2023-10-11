from __future__ import annotations

import numpy as np


def lower_upper_decomposition(table: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
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
            total = sum(lower[i][k] * upper[k][j] for k in range(j))
            upper[i][j] = table[i][j] - total
    return lower, upper

matrix = np.array([[2, -2, 1], [0, 1, 2], [5, 3, 1]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)
lower_mat
upper_mat

matrix = np.array([[4, 3], [6, 3]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)
lower_mat
upper_mat

matrix = np.array([[2, -2, 1], [0, 1, 2]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)

matrix = np.array([[0, 1], [1, 0]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)

matrix = np.array([[1, 0], [1, 0]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)
lower_mat
upper_mat

matrix = np.array([[0, 1], [0, 1]])
lower_mat, upper_mat = lower_upper_decomposition(matrix)