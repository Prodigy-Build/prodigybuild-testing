import unittest

class TestPrefixEvaluation(unittest.TestCase):

    def setUp(self):
        self.calc = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: x / y,
        }

    def test_is_operand(self):
        self.assertTrue(is_operand("1"))
        self.assertFalse(is_operand("+"))

    def test_evaluate(self):
        self.assertEqual(evaluate("+ 9 * 2 6"), 21)
        self.assertEqual(evaluate("/ * 10 2 + 4 1 "), 4.0)
        with self.assertRaises(IndexError):
            evaluate("+ 9")
        # when division by zero occurs
        with self.assertRaises(ZeroDivisionError):
            evaluate("/ 9 0")

if __name__ == "__main__":
    unittest.main()