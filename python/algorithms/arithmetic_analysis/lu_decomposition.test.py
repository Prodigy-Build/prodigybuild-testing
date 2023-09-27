from typing import List, Tuple
import numpy as np

def lu_decomposition(matrix: List[List[int]]) -> Tuple[List[List[int]], List[List[int]]]:
    rows = len(matrix)
    cols = len(matrix[0])
    if rows != cols:
        raise ValueError(f"'matrix' has to be of square shaped array but got a {rows}x{cols} array.")
    
    L = [[0] * cols for _ in range(rows)]
    U = [[0] * cols for _ in range(rows)]

    for i in range(cols):
        for j in range(i, cols):
            U[i][j] = matrix[i][j] - sum(L[i][k] * U[k][j] for k in range(i))
        for j in range(i+1, rows):
            L[j][i] = (matrix[j][i] - sum(L[j][k] * U[k][i] for k in range(i))) / U[i][i]
        L[i][i] = 1

    return L, U