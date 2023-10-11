import unittest

class TestJacobiIterationMethod(unittest.TestCase):
    def test_jacobi_iteration_method(self):
        coefficient = np.array([[4, 1, 1], [1, 5, 2], [1, 2, 4]])
        constants = np.array([[2], [-6], [-4]])
        init_val = [0.5, -0.5, -0.5]
        iterations = 3
        result = jacobi_iteration_method(coefficient, constants, init_val, iterations)
        expected_result = [0.909375, -1.14375, -0.7484375]
        self.assertEqual(result, expected_result)

unittest.main()