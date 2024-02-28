import unittest

class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_length(self):
        self.assertEqual(len(self.stack), 0)
        self.stack.push(1)
        self.assertEqual(len(self.stack), 1)
        
    def test_push(self):
        self.stack.push(1)
        self.assertEqual(self.stack.top(), 1)
        self.stack.push(2)
        self.assertEqual(self.stack.top(), 2)

    def test_pop(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(self.stack.pop(), 2)
        self.assertEqual(self.stack.top(), 1)
        self.assertEqual(self.stack.pop(), 1)
        self.assertEqual(self.stack.pop(), None)

    def test_top(self):
        self.assertEqual(self.stack.top(), None)
        self.stack.push(1)
        self.assertEqual(self.stack.top(), 1)

    def test_is_empty(self):
        self.assertEqual(self.stack.is_empty(), True)
        self.stack.push(1)
        self.assertEqual(self.stack.is_empty(), False)

    def test_print_stack(self):
        self.stack.push(1)
        self.stack.push(2)
        self.stack.push(3)
        self.stack.push(4)
        self.assertEqual(self.stack.print_stack(), '4->3->2->1->')

if __name__ == '__main__':
    unittest.main()