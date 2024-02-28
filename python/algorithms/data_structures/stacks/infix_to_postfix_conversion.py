"""
Unit test cases
"""

import unittest

class TestInfixToPostfix(unittest.TestCase):

    def test_balanced_parentheses(self):
        self.assertEqual(infix_to_postfix("(1*(2+3)+4))"), ValueError("Mismatched parentheses"))
        self.assertEqual(infix_to_postfix(""), '')
        self.assertEqual(infix_to_postfix("3+2"), '3 2 +')
        self.assertEqual(infix_to_postfix("(3+4)*5-6"), '3 4 + 5 * 6 -')
        self.assertEqual(infix_to_postfix("(1+2)*3/4-5"), '1 2 + 3 * 4 / 5 -')
        self.assertEqual(infix_to_postfix("a+b*c+(d*e+f)*g"), 'a b c * + d e * f + g * +')
        self.assertEqual(infix_to_postfix("x^y/(5*z)+2"), 'x y ^ 5 z * / 2 +')
        
    def test_precedence(self):
        self.assertEqual(precedence('*'), 2)
        self.assertEqual(precedence('/'), 2)
        self.assertEqual(precedence('^'), 3)
        self.assertEqual(precedence('abc'), -1)
        self.assertEqual(precedence('+'), 1)
        self.assertEqual(precedence('-'), 1)


if __name__ == "__main__":
    unittest.main()