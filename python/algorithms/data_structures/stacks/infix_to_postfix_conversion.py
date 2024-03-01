from typing import List
from algorithms.data_structures.stacks.balanced_parentheses import balanced_parentheses
from algorithms.data_structures.stacks.stack import Stack


def precedence(char: str) -> int:
    return {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}.get(char, -1)


def infix_to_postfix(expression_str: str) -> str:
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


def test_infix_to_postfix():
    assert infix_to_postfix("(1*(2+3)+4))") == ValueError("Mismatched parentheses")
    assert infix_to_postfix("") == ""
    assert infix_to_postfix("3+2") == "3 2 +"
    assert infix_to_postfix("(3+4)*5-6") == "3 4 + 5 * 6 -"
    assert infix_to_postfix("(1+2)*3/4-5") == "1 2 + 3 * 4 / 5 -"
    assert infix_to_postfix("a+b*c+(d*e+f)*g") == "a b c * + d e * f + g * +"
    assert infix_to_postfix("x^y/(5*z)+2") == "x y ^ 5 z * / 2 +"
    assert infix_to_postfix("a+b*(c^d-e)^(f+g*h)-i") == "a b c d ^ e - f g h * + ^ * i -"


test_infix_to_postfix()