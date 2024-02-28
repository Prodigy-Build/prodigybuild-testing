```python
import unittest
from stack_with_singly_linked_list import LinkedStack

class TestLinkedStack(unittest.TestCase):

    def test_push(self):
        s = LinkedStack()
        s.push(1)
        s.push(2)
        s.push(3)
        self.assertEqual(str(s), '3->2->1')
        
    def test_pop(self):
        s = LinkedStack()
        s.push(1)
        s.push(2)
        s.pop()
        self.assertEqual(str(s), '1')
        
    def test_peek(self):
        s = LinkedStack()
        s.push(1)
        s.push(2)
        self.assertEqual(s.peek(), 2)
        
    def test_clear(self):
        s = LinkedStack()
        s.push(1)
        s.push(2)
        s.clear()
        self.assertEqual(str(s), '')
        
    def test_is_empty(self):
        s = LinkedStack()
        self.assertTrue(s.is_empty())
        s.push(1)
        self.assertFalse(s.is_empty())

    def test_len(self):
        s = LinkedStack()
        s.push(1)
        s.push(2)
        self.assertEqual(len(s), 2)

    def test_pop_from_empty(self):
        s = LinkedStack()
        with self.assertRaises(IndexError):
            s.pop()

if __name__ == "__main__":
    unittest.main()
```