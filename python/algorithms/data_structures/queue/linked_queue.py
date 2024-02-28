import unittest
from linked_queue import LinkedQueue

class TestLinkedQueue(unittest.TestCase):

    def setUp(self):
        self.queue = LinkedQueue()

    def test_empty_queue(self):
        self.assertTrue(self.queue.is_empty())
        with self.assertRaises(IndexError):
            self.queue.get()

    def test_put(self):
        self.queue.put(5)
        self.assertEqual(len(self.queue), 1)
        self.assertEqual(self.queue.get(), 5)

    def test_get(self):
        self.queue.put(5)
        self.queue.put("test")
        self.assertEqual(self.queue.get(), 5)
        self.assertEqual(self.queue.get(), "test")

    def test_clear(self):
        self.queue.put(5)
        self.queue.put("test")
        self.queue.clear()
        self.assertTrue(self.queue.is_empty())

if __name__ == "__main__":
    unittest.main()