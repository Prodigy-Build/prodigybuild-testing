import unittest
from stacks.evaluate_postfix_notations import evaluate_postfix


class TestEvaluatePostfix(unittest.TestCase):

    def test_evaluate_postfix(self):
        self.assertEqual(evaluate_postfix(["2", "1", "+", "3", "*"]), 9)
        self.assertEqual(evaluate_postfix(["4", "13", "5", "/", "+"]), 6)
        self.assertEqual(evaluate_postfix([]), 0)
        self.assertEqual(evaluate_postfix(["3", "2", "*", "4", "/"]), 1.5)
        self.assertEqual(evaluate_postfix(["3", "2", "*", "7", "+"]), 13)


if __name__ == "__main__":
    unittest.main()