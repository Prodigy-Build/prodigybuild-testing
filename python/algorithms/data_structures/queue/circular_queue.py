import unittest
from circular_queue import CircularQueue

class TestCircularQueue(unittest.TestCase):

    def test_len(self):
        cq = CircularQueue(3)
        self.assertEqual(len(cq), 0)
        cq.enqueue(10)
        self.assertEqual(len(cq), 1)
        cq.enqueue(20)
        self.assertEqual(len(cq), 2)

    def test_is_empty(self):
        cq = CircularQueue(3)
        self.assertEqual(cq.is_empty(), True)
        cq.enqueue(10)
        self.assertEqual(cq.is_empty(), False)

    def test_first(self):
        cq = CircularQueue(3)
        self.assertEqual(cq.first(), False)
        cq.enqueue(10)
        self.assertEqual(cq.first(), 10)

    def test_enqueue(self):
        cq = CircularQueue(3)
        cq.enqueue(10)
        cq.enqueue(20)
        self.assertEqual(cq.first(), 10)
        with self.assertRaises(Exception): 
            cq.enqueue(30)
            
    def test_dequeue(self):
        cq = CircularQueue(3)
        with self.assertRaises(Exception): 
            cq.dequeue()
        cq.enqueue(10)
        cq.enqueue(20)
        self.assertEqual(cq.dequeue(), 10)
        self.assertEqual(cq.dequeue(), 20)
        with self.assertRaises(Exception): 
            cq.dequeue()

            
if __name__ == "__main__":
    unittest.main()