import unittest

class TestQueue(unittest.TestCase):

    def setUp(self):
        self.queue = Queue()
        
    def test_put(self):
        self.queue.put('Test')
        self.assertEqual(str(self.queue), '<Test>')
        self.assertEqual(self.queue.size(), 1)

    def test_get(self):
        self.queue.put('Test')
        self.assertEqual(self.queue.get(), 'Test')
        self.assertEqual(self.queue.size(), 0)

    def test_rotate(self):
        self.queue.put('Test1')
        self.queue.put('Test2')
        self.queue.rotate(1)
        self.assertEqual(str(self.queue), '<Test2, Test1>')
        
    def test_front(self):
        self.queue.put('Test1')
        self.queue.put('Test2')
        self.assertEqual(self.queue.front(), 'Test1')
        
    def test_size(self):
        self.queue.put('Test1')
        self.queue.put('Test2')
        self.assertEqual(self.queue.size(), 2)

if __name__ == '__main__':
    unittest.main()