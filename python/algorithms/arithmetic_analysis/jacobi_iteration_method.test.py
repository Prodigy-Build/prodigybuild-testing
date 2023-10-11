import unittest
from unittest.mock import patch
import numpy as np
from numpy.typing import NDArray
from numpy import float64


class TestJacobiIterationMethod(unittest.TestCase):
    def setUp(self):
        self.coefficient_matrix = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        self.constant_matrix = np.array([[2], [-6], [-4]])
        self.init_val = [0.5, -0.5, -0.5]
        self.iterations = 3

    def test_jacobi_iteration_method(self):
        expected = [0.909375, -1.14375, -0.7484375]
        result = jacobi_iteration_method(
            self.coefficient_matrix, self.constant_matrix, self.init_val, self.iterations
        )
        self.assertEqual(result, expected)

    def test_coefficient_matrix_dimensions(self):
        coefficient_matrix = np.array([[4, 1, 1], [1, 5, 2]])
        with self.assertRaises(ValueError):
            jacobi_iteration_method(
                coefficient_matrix, self.constant_matrix, self.init_val, self.iterations
            )

    def test_constant_matrix_dimensions(self):
        constant_matrix = np.array([[2], [-6]])
        with self.assertRaises(ValueError):
            jacobi_iteration_method(
                self.coefficient_matrix, constant_matrix, self.init_val, self.iterations
            )

    def test_number_of_initial_values(self):
        init_val = [0.5, -0.5]
        with self.assertRaises(ValueError):
            jacobi_iteration_method(
                self.coefficient_matrix, self.constant_matrix, init_val, self.iterations
            )

    def test_iterations_value(self):
        iterations = 0
        with self.assertRaises(ValueError):
            jacobi_iteration_method(
                self.coefficient_matrix, self.constant_matrix, self.init_val, iterations
            )


if __name__ == "__main__":
    unittest.main()
