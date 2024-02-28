```python
import unittest
from double_ended_queue import Deque

class TestDeque(unittest.TestCase):
    def test_append(self):
        deque = Deque()
        deque.append(1)
        deque.append(2)
        deque.append(3)
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque.pop(), 3)
        self.assertEqual(deque.pop(), 2)
        self.assertEqual(deque.pop(), 1)
        self.assertEqual(len(deque), 0)

    def test_appendleft(self):
        deque = Deque()
        deque.appendleft(1)
        deque.appendleft(2)
        deque.appendleft(3)
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque.popleft(), 3)
        self.assertEqual(deque.popleft(), 2)
        self.assertEqual(deque.popleft(), 1)
        self.assertEqual(len(deque), 0)

    def test_extend(self):
        deque = Deque()
        deque.extend([1, 2, 3])
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque.pop(), 3)
        self.assertEqual(deque.pop(), 2)
        self.assertEqual(deque.pop(), 1)
        self.assertEqual(len(deque), 0)

    def test_extendleft(self):
        deque = Deque()
        deque.extendleft([1, 2, 3])
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque.popleft(), 3)
        self.assertEqual(deque.popleft(), 2)
        self.assertEqual(deque.popleft(), 1)
        self.assertEqual(len(deque), 0)

    def test_pop(self):
        deque = Deque([1, 2, 3])
        self.assertEqual(deque.pop(), 3)
        self.assertEqual(deque.pop(), 2)
        self.assertEqual(deque.pop(), 1)
        self.assertEqual(len(deque), 0)

    def test_popleft(self):
        deque = Deque([1, 2, 3])
        self.assertEqual(deque.popleft(), 1)
        self.assertEqual(deque.popleft(), 2)
        self.assertEqual(deque.popleft(), 3)
        self.assertEqual(len(deque), 0)

    def test_is_empty(self):
        deque = Deque()
        self.assertTrue(deque.is_empty())
        deque.append(1)
        self.assertFalse(deque.is_empty())

    def test_len(self):
        deque = Deque()
        self.assertEqual(len(deque), 0)
        deque.append(1)
        self.assertEqual(len(deque), 1)
        deque.append(2)
        self.assertEqual(len(deque), 2)
        deque.pop()
        self.assertEqual(len(deque), 1)
        deque.pop()
        self.assertEqual(len(deque), 0)

    def test_eq(self):
        deque1 = Deque([1, 2, 3])
        deque2 = Deque([1, 2, 3])
        deque3 = Deque([1, 2])
        self.assertEqual(deque1, deque2)
        self.assertNotEqual(deque1, deque3)

    def test_iter(self):
        deque = Deque([1, 2, 3])
        values = []
        for val in deque:
            values.append(val)
        self.assertEqual(values, [1, 2, 3])

    def test_repr(self):
        deque = Deque([1, 2, 3])
        self.assertEqual(repr(deque), "[1, 2, 3]")

if __name__ == "__main__":
    unittest.main()
```
