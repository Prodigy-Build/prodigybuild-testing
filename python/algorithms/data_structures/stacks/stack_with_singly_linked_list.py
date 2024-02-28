class TestLinkedStack(unittest.TestCase):
    def test_is_empty(self):
        stack = LinkedStack()
        self.assertTrue(stack.is_empty())
        stack.push(1)
        self.assertFalse(stack.is_empty())

    def test_push(self):
        stack = LinkedStack()
        stack.push("Python")
        stack.push("Java")
        stack.push("C")
        self.assertEqual(str(stack), "C->Java->Python")

    def test_pop(self):
        stack = LinkedStack()
        with self.assertRaises(IndexError):
            stack.pop()
        stack.push("c")
        stack.push("b")
        stack.push("a")
        self.assertEqual(stack.pop(), "a")
        self.assertEqual(stack.pop(), "b")
        self.assertEqual(stack.pop(), "c")

    def test_peek(self):
        stack = LinkedStack()
        stack.push("Java")
        stack.push("C")
        stack.push("Python")
        self.assertEqual(stack.peek(), "Python")

    def test_clear(self):
        stack = LinkedStack()
        stack.push("Java")
        stack.push("C")
        stack.push("Python")
        self.assertEqual(str(stack), "Python->C->Java")
        stack.clear()
        self.assertEqual(len(stack), 0)


if __name__ == "__main__":
    unittest.main()