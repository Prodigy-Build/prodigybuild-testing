import unittest

class TestPostfixEvaluation(unittest.TestCase):

    def test_solve_basic(self):
        self.assertEqual(solve("5 6 9 * +".split(" ")), 59)
    
    def test_solve_basic_with_subtraction(self):
        self.assertEqual(solve("5 6 -".split(" ")), -1)

    def test_solve_complex(self):
        self.assertEqual(solve("2 3 4 * + 5 -".split(" ")), 5)

    def test_solve_with_power(self):
        self.assertEqual(solve("2 3 ^".split(" ")), 8)

    def test_solve_with_division(self):
        self.assertEqual(solve("8 4 /".split(" ")), 2)


if __name__ == "__main__":
    unittest.main()