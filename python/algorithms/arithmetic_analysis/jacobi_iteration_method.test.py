import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


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
    except ValueError:
        pass

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 3
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError:
        pass

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5]
    iterations = 3
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError:
        pass

    coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
    constant = np.array([[2], [-6], [-4]])
    init_val = [0.5, -0.5, -0.5]
    iterations = 0
    try:
        jacobi_iteration_method(coefficient, constant, init_val, iterations)
    except ValueError:
        pass


if __name__ == "__main__":
    import numpy as np
    from numpy import float64
    from numpy.typing import NDArray

    def jacobi_iteration_method(
            coefficient_matrix: NDArray[float64],
            constant_matrix: NDArray[float64],
            init_val: list[int],
            iterations: int,
    ) -> list[float]:
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

        table: NDArray[float64] = np.concatenate(
            (coefficient_matrix, constant_matrix), axis=1
        )

        rows, cols = table.shape

        strictly_diagonally_dominant(table)

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

    def strictly_diagonally_dominant(table: NDArray[float64]) -> bool:
        rows, cols = table.shape

        is_diagonally_dominant = True

        for i in range(0, rows):
            total = 0
            for j in range(0, cols - 1):
                if i == j:
                    continue
                else:
                    total += table[i][j]

            if table[i][i] <= total:
                raise ValueError("Coefficient matrix is not strictly diagonally dominant")

        return is_diagonally_dominant

    test_jacobi_iteration_method()