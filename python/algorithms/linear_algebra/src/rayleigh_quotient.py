import unittest
from typing import Any

import numpy as np


def is_hermitian(matrix: np.ndarray) -> bool:
    return np.array_equal(matrix, matrix.conjugate().T)


def rayleigh_quotient(a: np.ndarray, v: np.ndarray) -> Any:
    v_star = v.conjugate().T
    v_star_dot = v_star.dot(a)
    assert isinstance(v_star_dot, np.ndarray)
    return (v_star_dot.dot(v)) / (v_star.dot(v))


class TestRayleighQuotient(unittest.TestCase):
    def test_is_hermitian(self):
        a = np.array([[2, 2 + 1j, 4], [2 - 1j, 3, 1j], [4, -1j, 1]])
        self.assertTrue(is_hermitian(a))

        a = np.array([[2, 2 + 1j, 4 + 1j], [2 - 1j, 3, 1j], [4, -1j, 1]])
        self.assertFalse(is_hermitian(a))

    def test_rayleigh_quotient(self):
        a = np.array([[1, 2, 4], [2, 3, -1], [4, -1, 1]])
        v = np.array([[1], [2], [3]])
        self.assertEqual(rayleigh_quotient(a, v), np.array([[3.]]))


if __name__ == "__main__":
    unittest.main()