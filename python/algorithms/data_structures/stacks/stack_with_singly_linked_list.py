class TestLinkedStack:
    def test_is_empty(self):
        stack = LinkedStack()
        assert stack.is_empty() == True
        stack.push(1)
        assert stack.is_empty() == False

    def test_push(self):
        stack = LinkedStack()
        stack.push("Python")
        stack.push("Java")
        stack.push("C")
        assert str(stack) == "C->Java->Python"

    def test_pop(self):
        stack = LinkedStack()
        try:
            stack.pop()
        except IndexError as e:
            assert str(e) == "pop from empty stack"
        stack.push("c")
        stack.push("b")
        stack.push("a")
        assert stack.pop() == "a"
        assert stack.pop() == "b"
        assert stack.pop() == "c"

    def test_peek(self):
        stack = LinkedStack()
        stack.push("Java")
        stack.push("C")
        stack.push("Python")
        assert stack.peek() == "Python"

    def test_clear(self):
        stack = LinkedStack()
        stack.push("Java")
        stack.push("C")
        stack.push("Python")
        assert str(stack) == "Python->C->Java"
        stack.clear()
        assert len(stack) == 0