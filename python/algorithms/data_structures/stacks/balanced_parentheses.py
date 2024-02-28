import unittest
from .stack import Stack
from .balanced_parentheses import balanced_parentheses


class TestBalancedParentheses(unittest.TestCase):

    def test_balanced_parentheses(self):
        self.assertEqual(balanced_parentheses("([{}])"), True)
        self.assertEqual(balanced_parentheses("[()]{}{[()()]()}"), True)
        self.assertEqual(balanced_parentheses("[(])"), False)
        self.assertEqual(balanced_parentheses("1+2*3-4"), True)
        self.assertEqual(balanced_parentheses(""), True)
        self.assertEqual(balanced_parentheses("((()))"), True)
        self.assertEqual(balanced_parentheses("((())"), False)
        self.assertEqual(balanced_parentheses("(()))"), False)
        

if __name__ == '__main__':
    unittest.main()