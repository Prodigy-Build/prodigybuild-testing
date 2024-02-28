from typing import List
import unittest

from algorithms.data_structures.stacks.balanced_parentheses import balanced_parentheses
from algorithms.data_structures.stacks.stack import Stack


def precedence(char: str) -> int:
    """
    Return integer value representing an operator's precedence, or
    order of operation.
    https://en.wikipedia.org/wiki/Order_of_operations
    """
    return {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}.get(char, -1)


def infix_to_postfix(expression_str: str) -> str:
    """
    >>> infix_to_postfix("(1*(2+3)+4))")
    Traceback (most recent call last):
        ...
    ValueError: Mismatched parentheses
    >>> infix_to_postfix("")
    ''
    >>> infix_to_postfix("3+2")
    '3 2 +'
    >>> infix_to_postfix("(3+4)*5-6")
    '3 4 + 5 * 6 -'
    >>> infix_to_postfix("(1+2)*3/4-5")
    '1 2 + 3 * 4 / 5 -'
    >>> infix_to_postfix("a+b*c+(d*e+f)*g")
    'a b c * + d e * f + g * +'
    >>> infix_to_postfix("x^y/(5*z)+2")
    'x y ^ 5 z * / 2 +'
    """
    if not balanced_parentheses(expression_str):
        raise ValueError("Mismatched parentheses")
    stack: Stack[str] = Stack()
    postfix = []
    for char in expression_str:
        if char.isalpha() or char.isdigit():
            postfix.append(char)
        elif char == "(":
            stack.push(char)
        elif char == ")":
            while not stack.is_empty() and stack.peek() != "(":
                postfix.append(stack.pop())
            stack.pop()
        else:
            while not stack.is_empty() and precedence(char) <= precedence(stack.peek()):
                postfix.append(stack.pop())
            stack.push(char)
    while not stack.is_empty():
        postfix.append(stack.pop())
    return " ".join(postfix)


class TestInfixToPostfixConversion(unittest.TestCase):
    def test_mismatched_parentheses(self):
        with self.assertRaises(ValueError):
            infix_to_postfix("(1*(2+3)+4))")

    def test_empty_expression(self):
        self.assertEqual(infix_to_postfix(""), "")

    def test_simple_expression(self):
        self.assertEqual(infix_to_postfix("3+2"), "3 2 +")

    def test_complex_expression(self):
        self.assertEqual(infix_to_postfix("(3+4)*5-6"), "3 4 + 5 * 6 -")
        self.assertEqual(infix_to_postfix("(1+2)*3/4-5"), "1 2 + 3 * 4 / 5 -")
        self.assertEqual(infix_to_postfix("a+b*c+(d*e+f)*g"), "a b c * + d e * f + g * +")
        self.assertEqual(infix_to_postfix("x^y/(5*z)+2"), "x y ^ 5 z * / 2 +")


if __name__ == "__main__":
    unittest.main()