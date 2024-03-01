from .stack import Stack


def balanced_parentheses(parentheses: str) -> bool:
    stack: Stack[str] = Stack()
    bracket_pairs = {"(": ")", "[": "]", "{": "}"}
    for bracket in parentheses:
        if bracket in bracket_pairs:
            stack.push(bracket)
        elif bracket in (")", "]", "}"):
            if stack.is_empty() or bracket_pairs[stack.pop()] != bracket:
                return False
    return stack.is_empty()