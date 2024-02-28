import unittest

class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack: Stack[int] = Stack(10)

    def test_stack_bool(self):
        self.assertEqual(bool(self.stack), False)

    def test_stack_is_empty(self):
        self.assertEqual(self.stack.is_empty(), True)

    def test_stack_is_full(self):
        self.assertEqual(self.stack.is_full(), False)

    def test_stack_str(self):
        self.assertEqual(str(self.stack), "[]")

    def test_stack_underflow_pop(self):
        with self.assertRaises(StackUnderflowError):
            _ = self.stack.pop()

    def test_stack_underflow_peek(self):
        with self.assertRaises(StackUnderflowError):
            _ = self.stack.peek()

    def test_stack_push(self):
        for i in range(10):
            self.assertEqual(self.stack.size(), i)
            self.stack.push(i)
        self.assertEqual(bool(self.stack), True)
        self.assertEqual(self.stack.is_empty(), False)
        self.assertEqual(self.stack.is_full(), True)
        self.assertEqual(str(self.stack), str(list(range(10))))
    
    def test_stack_pop_and_peek(self):
        self.assertEqual(self.stack.pop(), 9)
        self.assertEqual(self.stack.peek(), 8)
        self.stack.push(100)
        self.assertEqual(str(self.stack), str([0, 1, 2, 3, 4, 5, 6, 7, 8, 100]))

    def test_stack_overflow(self):
        with self.assertRaises(StackOverflowError):
            self.stack.push(200)
        self.assertEqual(self.stack.is_empty(), False)
        self.assertEqual(self.stack.size(), 10)

    def test_stack_contains(self):    
        self.assertTrue(5 in self.stack)
        self.assertFalse(55 in self.stack)


if __name__ == "__main__":
    unittest.main()