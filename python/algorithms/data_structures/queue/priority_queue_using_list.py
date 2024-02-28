```python
import unittest
from algorithms.data_structures.queue.priority_queue_using_list import FixedPriorityQueue, ElementPriorityQueue, OverFlowError, UnderFlowError


class TestFixedPriorityQueue(unittest.TestCase):
    def test_enqueue(self):
        fpq = FixedPriorityQueue()
        fpq.enqueue(0, 10)
        fpq.enqueue(1, 70)
        fpq.enqueue(0, 100)
        fpq.enqueue(2, 1)
        fpq.enqueue(2, 5)
        fpq.enqueue(1, 7)
        fpq.enqueue(2, 4)
        fpq.enqueue(1, 64)
        fpq.enqueue(0, 128)
        self.assertEqual(str(fpq), "Priority 0: [10, 100, 128]\nPriority 1: [70, 7, 64]\nPriority 2: [1, 5, 4]")

    def test_dequeue(self):
        fpq = FixedPriorityQueue()
        fpq.enqueue(0, 10)
        fpq.enqueue(1, 70)
        fpq.enqueue(0, 100)
        fpq.enqueue(2, 1)
        fpq.enqueue(2, 5)
        fpq.enqueue(1, 7)
        fpq.enqueue(2, 4)
        fpq.enqueue(1, 64)
        fpq.enqueue(0, 128)
        self.assertEqual(fpq.dequeue(), 10)
        self.assertEqual(fpq.dequeue(), 100)
        self.assertEqual(fpq.dequeue(), 128)
        self.assertEqual(fpq.dequeue(), 70)
        self.assertEqual(fpq.dequeue(), 7)
        self.assertEqual(str(fpq), "Priority 0: []\nPriority 1: [64]\nPriority 2: [1, 5, 4]")
        self.assertEqual(fpq.dequeue(), 64)
        self.assertEqual(fpq.dequeue(), 1)
        self.assertEqual(fpq.dequeue(), 5)
        self.assertEqual(fpq.dequeue(), 4)
        with self.assertRaises(UnderFlowError):
            fpq.dequeue()
        self.assertEqual(str(fpq), "Priority 0: []\nPriority 1: []\nPriority 2: []")


class TestElementPriorityQueue(unittest.TestCase):
    def test_enqueue(self):
        epq = ElementPriorityQueue()
        epq.enqueue(10)
        epq.enqueue(70)
        epq.enqueue(4)
        epq.enqueue(1)
        epq.enqueue(5)
        epq.enqueue(7)
        epq.enqueue(4)
        epq.enqueue(64)
        epq.enqueue(128)
        self.assertEqual(str(epq), "[10, 70, 4, 1, 5, 7, 4, 64, 128]")

    def test_dequeue(self):
        epq = ElementPriorityQueue()
        epq.enqueue(10)
        epq.enqueue(70)
        epq.enqueue(4)
        epq.enqueue(1)
        epq.enqueue(5)
        epq.enqueue(7)
        epq.enqueue(4)
        epq.enqueue(64)
        epq.enqueue(128)
        self.assertEqual(epq.dequeue(), 1)
        self.assertEqual(epq.dequeue(), 4)
        self.assertEqual(epq.dequeue(), 4)
        self.assertEqual(epq.dequeue(), 5)
        self.assertEqual(epq.dequeue(), 7)
        self.assertEqual(str(epq), "[10, 70, 64]")
        self.assertEqual(epq.dequeue(), 10)
        self.assertEqual(epq.dequeue(), 70)
        self.assertEqual(epq.dequeue(), 128)
        with self.assertRaises(UnderFlowError):
            epq.dequeue()
        self.assertEqual(str(epq), "[]")


if __name__ == "__main__":
    unittest.main()
```