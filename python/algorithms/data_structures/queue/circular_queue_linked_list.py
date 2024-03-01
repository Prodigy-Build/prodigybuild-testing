from typing import Any
import unittest

class TestCircularQueueLinkedList(unittest.TestCase):
    def test_is_empty(self):
        cq = CircularQueueLinkedList()
        self.assertTrue(cq.is_empty())
        cq.enqueue('a')
        self.assertFalse(cq.is_empty())
        cq.dequeue()
        self.assertTrue(cq.is_empty())

    def test_first(self):
        cq = CircularQueueLinkedList()
        with self.assertRaises(Exception):
            cq.first()
        cq.enqueue('a')
        self.assertEqual(cq.first(), 'a')
        cq.dequeue()
        with self.assertRaises(Exception):
            cq.first()
        cq.enqueue('b')
        cq.enqueue('c')
        self.assertEqual(cq.first(), 'b')

    def test_enqueue(self):
        cq = CircularQueueLinkedList()
        cq.enqueue('a')
        cq.enqueue('b')
        self.assertEqual(cq.dequeue(), 'a')
        self.assertEqual(cq.dequeue(), 'b')
        with self.assertRaises(Exception):
            cq.dequeue()

    def test_dequeue(self):
        cq = CircularQueueLinkedList()
        with self.assertRaises(Exception):
            cq.dequeue()
        cq.enqueue('a')
        self.assertEqual(cq.dequeue(), 'a')
        with self.assertRaises(Exception):
            cq.dequeue()

if __name__ == '__main__':
    unittest.main()