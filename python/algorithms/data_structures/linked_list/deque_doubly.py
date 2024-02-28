class TestLinkedDeque(unittest.TestCase):
    def setUp(self):
        self.deque = LinkedDeque()

    def test_first_empty_deque(self):
        self.assertRaises(Exception, self.deque.first)

    def test_first_non_empty_deque(self):
        self.deque.add_first('A')
        self.assertEqual(self.deque.first(), 'A')

    def test_last_empty_deque(self):
        self.assertRaises(Exception, self.deque.last)

    def test_last_non_empty_deque(self):
        self.deque.add_last('A')
        self.assertEqual(self.deque.last(), 'A')

    def test_add_first(self):
        self.deque.add_first('A')
        self.assertEqual(self.deque.first(), 'A')
        self.deque.add_first('B')
        self.assertEqual(self.deque.first(), 'B')

    def test_add_last(self):
        self.deque.add_last('A')
        self.assertEqual(self.deque.last(), 'A')
        self.deque.add_last('B')
        self.assertEqual(self.deque.last(), 'B')

    def test_remove_first_empty_deque(self):
        self.assertRaises(IndexError, self.deque.remove_first)

    def test_remove_first_non_empty_deque(self):
        self.deque.add_first('A')
        self.assertEqual(self.deque.remove_first(), 'A')
        self.assertTrue(self.deque.is_empty())

    def test_remove_last_empty_deque(self):
        self.assertRaises(IndexError, self.deque.remove_last)

    def test_remove_last_non_empty_deque(self):
        self.deque.add_first('A')
        self.assertEqual(self.deque.remove_last(), 'A')
        self.assertTrue(self.deque.is_empty())

if __name__ == '__main__':
    unittest.main()