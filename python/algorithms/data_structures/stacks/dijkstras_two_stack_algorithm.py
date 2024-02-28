import unittest

from python.algorithms.data_structures.stacks.dijkstras_two_stack_algorithm import dijkstras_two_stack_algorithm


class TestDijkstrasTwoStackAlgorithm(unittest.TestCase):
    def test_basic_calculation(self):
        equation = "(5 + 3)"
        self.assertEqual(dijkstras_two_stack_algorithm(equation), 8)

    def test_nested_expressions(self):
        equation = "((9 - (2 + 9)) + (8 - 1))"
        self.assertEqual(dijkstras_two_stack_algorithm(equation), 5)

    def test_multiple_nested_expressions(self):
        equation = "((((3 - 2) - (2 + 3)) + (2 - 4)) + 3)"
        self.assertEqual(dijkstras_two_stack_algorithm(equation), -3)

    def test_complex_expression(self):
        equation = "(5 + ((4 * 2) * (2 + 3)))"
        self.assertEqual(dijkstras_two_stack_algorithm(equation), 45)


if __name__ == '__main__':
    unittest.main()
