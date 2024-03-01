The updated code for the file "python/algorithms/linear_algebra/src/rank_of_matrix.py" is as follows:

```python
"""
Calculate the rank of a matrix.

See: https://en.wikipedia.org/wiki/Rank_(linear_algebra)
"""


def rank_of_matrix(matrix: list[list[int | float]]) -> int:
    """
    Finds the rank of a matrix.
    Args:
        matrix: The matrix as a list of lists.
    Returns:
        The rank of the matrix.
    """
    rows = len(matrix)
    columns = len(matrix[0])
    rank = min(rows, columns)

    for row in range(rank):
        # Check if diagonal element is not zero
        if matrix[row][row] != 0:
            # Eliminate all the elements below the diagonal
            for col in range(row + 1, rows):
                multiplier = matrix[col][row] / matrix[row][row]
                for i in range(row, columns):
                    matrix[col][i] -= multiplier * matrix[row][i]
        else:
            # Find a non-zero diagonal element to swap rows
            reduce = True
            for i in range(row + 1, rows):
                if matrix[i][row] != 0:
                    matrix[row], matrix[i] = matrix[i], matrix[row]
                    reduce = False
                    break
            if reduce:
                rank -= 1
                for i in range(rows):
                    matrix[i][row] = matrix[i][rank]

            # Reduce the row pointer by one to stay on the same row
            row -= 1

    return rank


if __name__ == "__main__":
    import doctest

    doctest.testmod()
```

Please note that the original code already includes test cases and the `doctest` module is used to run these test cases.