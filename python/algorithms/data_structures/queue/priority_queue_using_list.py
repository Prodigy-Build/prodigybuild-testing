import unittest

class TestPriorityQueue(unittest.TestCase):
    def test_fixed_priority_queue(self):
        fpq = FixedPriorityQueue()
        with self.assertRaises(ValueError):
            fpq.enqueue(3, 10)
        with self.assertRaises(OverflowError):
            for _ in range(101):
                fpq.enqueue(2, 10)
        fpq.enqueue(0, 10)
        fpq.enqueue(1, 70)
        fpq.enqueue(0, 100)
        fpq.enqueue(2, 1)
        fpq.enqueue(2, 5)
        fpq.enqueue(1, 7)
        fpq.enqueue(2, 4)
        fpq.enqueue(1, 64)
        fpq.enqueue(0, 128)
        self.assertEqual(fpq.dequeue(),10)
        self.assertEqual(fpq.dequeue(),100)
        self.assertEqual(fpq.dequeue(),128)
        self.assertEqual(fpq.dequeue(),70)
        with self.assertRaises(UnderFlowError):
            for _ in range(7):
                fpq.dequeue()

    def test_element_priority_queue(self):
        epq = ElementPriorityQueue()
        with self.assertRaises(OverflowError):
            for _ in range(101):
                epq.enqueue(10)
        epq.enqueue(10)
        epq.enqueue(70)
        epq.enqueue(100)
        epq.enqueue(1)
        epq.enqueue(5)
        epq.enqueue(7)
        epq.enqueue(4)
        epq.enqueue(64)
        epq.enqueue(128)
        self.assertEqual(epq.dequeue(),1)
        self.assertEqual(epq.dequeue(),4)
        self.assertEqual(epq.dequeue(),5)
        self.assertEqual(epq.dequeue(),7)
        with self.assertRaises(UnderFlowError):
            for _ in range(8):
                epq.dequeue()


if __name__ == "__main__":
    unittest.main()