from typing import List, Tuple

def test_stack() -> None:
    stack = Stack()
    assert stack.is_empty() == True
    assert stack.print_stack() == "stack elements are:"
    
    for i in range(4):
        stack.push(i)
    
    assert stack.is_empty() == False
    assert stack.print_stack() == "stack elements are:\n3->2->1->0->"
    assert stack.top() == 3
    assert len(stack) == 4
    assert stack.pop() == 3
    assert stack.print_stack() == "stack elements are:\n2->1->0->"
    assert stack.is_empty() == False

test_stack()