import unittest
from numpy import array

class TestJacobiIterationMethod(unittest.TestCase):
    def test_jacobi_iteration_method(self):
        coefficient = array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constant = array([[2], [-6], [-4]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 3
        expected_result = [0.909375, -1.14375, -0.7484375]
        self.assertEqual(jacobi_iteration_method(coefficient, constant, init_val, iterations), expected_result)

        coefficient = array([[4, 1, 1], [1, 5, 2]])
        constant = array([[2], [-6], [-4]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 3
        with self.assertRaises(ValueError):
            jacobi_iteration_method(coefficient, constant, init_val, iterations)

        coefficient = array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constant = array([[2], [-6]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 3
        with self.assertRaises(ValueError):
            jacobi_iteration_method(coefficient, constant, init_val, iterations)

        coefficient = array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constant = array([[2], [-6], [-4]])
        init_val = [0.5, -0.5]
        iterations = 3
        with self.assertRaises(ValueError):
            jacobi_iteration_method(coefficient, constant, init_val, iterations)

        coefficient = array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constant = array([[2], [-6], [-4]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 0
        with self.assertRaises(ValueError):
            jacobi_iteration_method(coefficient, constant, init_val, iterations)
																						

unittest.main()