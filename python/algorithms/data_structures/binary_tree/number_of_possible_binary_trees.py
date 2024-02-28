import unittest

class TestBinaryTreeMethods(unittest.TestCase):

    def test_binomial_coefficient(self):
        self.assertEqual(binomial_coefficient(4, 2), 6)
        self.assertEqual(binomial_coefficient(2, 1), 2)

    def test_catalan_number(self):
        self.assertEqual(catalan_number(5), 42)
        self.assertEqual(catalan_number(6), 132)

    def test_factorial(self):
        self.assertEqual(factorial(5), 120)
        self.assertRaises(ValueError, factorial, -5)

    def test_binary_tree_count(self):
        self.assertEqual(binary_tree_count(5), 5040)
        self.assertEqual(binary_tree_count(6), 95040)

if __name__ == '__main__':
    unittest.main()