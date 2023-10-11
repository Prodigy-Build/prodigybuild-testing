import unittest
import numpy as np
from numpy import float64
from typing import List
from numpy.typing import NDArray


class TestJacobiIterationMethod(unittest.TestCase):
    def test_jacobi_iteration_method(self):
        coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constant = np.array([[2], [-6], [-4]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 3
        
        result = jacobi_iteration_method(coefficient, constant, init_val, iterations)
        expected = [0.909375, -1.14375, -0.7484375]
        self.assertEqual(result, expected)

unittest.main()