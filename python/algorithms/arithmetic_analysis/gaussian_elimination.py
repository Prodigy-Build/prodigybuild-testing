"""
Updated to the latest Python version
"""
from typing import List, Tuple


def retroactive_resolution(coefficients: List[List[float]], vector: List[float]) -> List[float]:
    """
    This function performs a retroactive linear system resolution for a triangular matrix
    """
    rows, columns = len(coefficients), len(coefficients[0])

    x = [0 for _ in range(rows)]
    for row in reversed(range(rows)):
        total = sum(coefficients[row][col] * x[col] for col in range(row + 1, columns))
        x[row] = (vector[row] - total) / coefficients[row][row]

    return x


def gaussian_elimination(coefficients: List[List[float]], vector: List[float]) -> List[float]:
    """
    This function performs Gaussian elimination method
    """
    # coefficients must to be a square matrix so we need to check first
    rows, columns = len(coefficients), len(coefficients[0])
    if rows != columns:
        return []

    # creating augmented matrix
    augmented_mat = [row + [v] for row, v in zip(coefficients, vector)]

    # scale the matrix leaving it triangular
    for row in range(rows - 1):
        pivot = augmented_mat[row][row]
        for col in range(row + 1, columns):
            factor = augmented_mat[col][row] / pivot
            augmented_mat[col] = [c - factor * augmented_mat[row][i] for i, c in enumerate(augmented_mat[col])]

    x = retroactive_resolution(augmented_mat, vector)

    return x


if __name__ == "__main__":
    pass  # Replace with your test code if needed
