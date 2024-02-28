import unittest
from double_ended_queue import Deque

class DequeTestCase(unittest.TestCase):
    def setUp(self):
        self.deque = Deque()

    def test_append(self):
        data = "Test"
        self.deque.append(data)
        self.assertEqual(self.deque.pop(), data)

    def test_appendleft(self):
        data = "Test"
        self.deque.appendleft(data)
        self.assertEqual(self.deque.popleft(), data)

    def test_extend(self):
        data = "Test data"
        self.deque.extend(data)
        for char in reversed(data):
            self.assertEqual(self.deque.pop(), char)

    def test_extendleft(self):
        data = "Test data"
        self.deque.extendleft(data)
        for char in data:
            self.assertEqual(self.deque.popleft(), char)

    def test_pop(self):
        data = "Testing pop"
        self.deque.extend(data)
        for char in reversed(data):
            self.assertEqual(self.deque.pop(), char)
        with self.assertRaises(IndexError):
            self.deque.pop()

    def test_popleft(self):
        data = "Testing popleft"
        self.deque.extend(data)
        for char in data:
            self.assertEqual(self.deque.popleft(), char)
        with self.assertRaises(IndexError):
            self.deque.popleft()

    def test_is_empty(self):
        self.assertTrue(self.deque.is_empty())
        self.deque.append("Test")
        self.assertFalse(self.deque.is_empty())

    def test_length(self):
        data = "Test length"
        self.deque.extend(data)
        self.assertEqual(len(self.deque), len(data))
        self.deque.pop()
        self.assertEqual(len(self.deque), len(data) - 1)

    def test_equality(self):
        other_deque = Deque()
        self.assertEqual(self.deque, other_deque)
        self.deque.append("Test")
        self.assertNotEqual(self.deque, other_deque)
        other_deque.append("Test")
        self.assertEqual(self.deque, other_deque)

    def test_iter(self):
        data = "Test iter"
        self.deque.extend(data)
        for deq_val, data_val in zip(self.deque, data):
            self.assertEqual(deq_val, data_val)

if __name__ == '__main__':
    unittest.main()