class TestLinkedQueue(unittest.TestCase):

    def test_is_empty(self):
        queue = LinkedQueue()
        self.assertTrue(queue.is_empty())
        queue.put(5)
        self.assertFalse(queue.is_empty())

    def test_put(self):
        queue = LinkedQueue()
        queue.put(5)
        self.assertEqual(len(queue), 1)
        self.assertEqual(str(queue), '5')
        queue.put(9)
        self.assertEqual(len(queue), 2)
        self.assertEqual(str(queue), '5 <- 9')
        queue.put('python')
        self.assertEqual(len(queue), 3)
        self.assertEqual(str(queue), '5 <- 9 <- python')

    def test_get(self):
        queue = LinkedQueue()
        with self.assertRaises(IndexError):
            queue.get()
        queue.put(5)
        queue.put(9)
        queue.put('python')
        self.assertEqual(queue.get(), 5)
        self.assertEqual(queue.get(), 9)
        self.assertEqual(queue.get(), 'python')
        with self.assertRaises(IndexError):
            queue.get()

    def test_clear(self):
        queue = LinkedQueue()
        for i in range(1, 6):
            queue.put(i)
        queue.clear()
        self.assertEqual(len(queue), 0)
        self.assertEqual(str(queue), '')

    def test_len(self):
        queue = LinkedQueue()
        for i in range(1, 6):
            queue.put(i)
        self.assertEqual(len(queue), 5)
        for i in range(1, 6):
            self.assertEqual(len(queue), 6 - i)
            _ = queue.get()
        self.assertEqual(len(queue), 0)

    def test_str(self):
        queue = LinkedQueue()
        for i in range(1, 4):
            queue.put(i)
        queue.put("Python")
        queue.put(3.14)
        queue.put(True)
        self.assertEqual(str(queue), '1 <- 2 <- 3 <- Python <- 3.14 <- True')


if __name__ == '__main__':
    unittest.main()