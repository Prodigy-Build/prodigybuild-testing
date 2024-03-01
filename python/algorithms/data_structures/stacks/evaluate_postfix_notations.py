from typing import List, Any

def evaluate_postfix(postfix_notation: List[str]) -> int:
    if not postfix_notation:
        return 0

    operations = {"+", "-", "*", "/"}
    stack: List[Any] = []

    for token in postfix_notation:
        if token in operations:
            b, a = stack.pop(), stack.pop()
            if token == "+":
                stack.append(a + b)
            elif token == "-":
                stack.append(a - b)
            elif token == "*":
                stack.append(a * b)
            else:
                if a * b < 0 and a % b != 0:
                    stack.append(a // b + 1)
                else:
                    stack.append(a // b)
        else:
            stack.append(int(token))

    return stack.pop()