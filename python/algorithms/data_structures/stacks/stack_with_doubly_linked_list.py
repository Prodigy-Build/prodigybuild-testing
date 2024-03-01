from typing import List, Tuple

def test_stack() -> None:
    stack = Stack()
    assert stack.is_empty() == True
    assert len(stack) == 0
    assert stack.top() == None

    stack.push(1)
    stack.push(2)
    stack.push(3)

    assert stack.is_empty() == False
    assert len(stack) == 3
    assert stack.top() == 3

    assert stack.pop() == 3
    assert stack.pop() == 2

    assert stack.is_empty() == False
    assert len(stack) == 1
    assert stack.top() == 1

    stack.pop()

    assert stack.is_empty() == True
    assert len(stack) == 0
    assert stack.top() == None

    print("All test cases pass")

test_stack()