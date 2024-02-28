class CircularQueueTest(unittest.TestCase):

    def test_len(self):
        cq = CircularQueue(5)
        self.assertEqual(len(cq), 0)
        cq.enqueue("A")
        self.assertEqual(len(cq), 1)

    def test_is_empty(self):
        cq = CircularQueue(5)
        self.assertTrue(cq.is_empty())
        cq.enqueue("A")
        self.assertFalse(cq.is_empty())

    def test_first(self):
        cq = CircularQueue(5)
        self.assertFalse(cq.first())
        cq.enqueue("A")
        self.assertEqual(cq.first(), 'A')

    def test_enqueue(self):
        cq = CircularQueue(5)
        self.assertEqual(cq.enqueue("A").size, 1)
        self.assertEqual(cq.first(), 'A')
        self.assertEqual(cq.enqueue("B").size, 2)
        self.assertEqual(cq.first(), 'A')

    def test_dequeue(self):
        cq = CircularQueue(5)
        with self.assertRaises(Exception):
            cq.dequeue()
        cq.enqueue("A").enqueue("B")
        self.assertEqual(cq.dequeue(), 'A')
        self.assertEqual(cq.size, 1)
        self.assertEqual(cq.first(), 'B')
        self.assertEqual(cq.dequeue(), 'B')
        with self.assertRaises(Exception):
            cq.dequeue()

if __name__ == '__main__':
    unittest.main()