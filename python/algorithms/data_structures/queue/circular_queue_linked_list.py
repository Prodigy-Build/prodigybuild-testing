import unittest

class TestCircularQueueLinkedList(unittest.TestCase):
    def setUp(self):
        self.cq = CircularQueueLinkedList(2)

    def test_enqueue(self):
        self.cq.enqueue('a')
        self.assertEqual(self.cq.first(), 'a')
        
        self.cq.enqueue('b')
        self.cq.dequeue()
        self.assertEqual(self.cq.first(), 'b')

        with self.assertRaises(Exception) as context:
            self.cq.enqueue('c')
        self.assertTrue('Full Queue' in str(context.exception))

    def test_dequeue(self):
        self.cq.enqueue('a')
        self.cq.enqueue('b')
        self.assertEqual(self.cq.dequeue(), 'a')
        self.assertEqual(self.cq.dequeue(), 'b')

        with self.assertRaises(Exception) as context:
            self.cq.dequeue()
        self.assertTrue('Empty Queue' in str(context.exception))

    def test_first(self):
        self.cq.enqueue('a')
        self.assertEqual(self.cq.first(), 'a')
        self.cq.dequeue()
        with self.assertRaises(Exception) as context:
            self.cq.first()
        self.assertTrue('Empty Queue' in str(context.exception))
    
    def test_is_empty(self):
        self.assertTrue(self.cq.is_empty())
        self.cq.enqueue('a')
        self.assertFalse(self.cq.is_empty())
        self.cq.dequeue()
        self.assertTrue(self.cq.is_empty())
        
if __name__ == "__main__":
    unittest.main()