import unittest

class TestQueue(unittest.TestCase):

    def setUp(self):
        self.queue = Queue()

    def test_enqueue(self):
        self.queue.put("Test")
        self.assertEqual(str(self.queue), "<'Test'>")

    def test_dequeue(self):
        self.queue.put("Test")
        self.queue.put("Case")
        self.assertEqual(self.queue.get(), "Test")

    def test_rotate(self):
        self.queue.put("Test")
        self.queue.put("Case")
        self.queue.rotate(1)
        self.assertEqual(str(self.queue), "<'Case', 'Test'>")

    def test_get_front(self):
        self.queue.put("Test")
        self.queue.put("Case")
        self.assertEqual(self.queue.get_front(), "Test")

    def test_size(self):
        self.queue.put("Test")
        self.queue.put("Case")
        self.assertEqual(self.queue.size(), 2)


if __name__ == '__main__':
    unittest.main()