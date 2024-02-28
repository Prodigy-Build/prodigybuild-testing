import unittest
from deque_doubly import LinkedDeque

class TestLinkedDeque(unittest.TestCase):
    def setUp(self):
        self.ldq = LinkedDeque()

    def test_first(self):
        self.assertIsNone(self.ldq.first() if self.ldq.is_empty() else None)
        self.ldq.add_first('A')
        self.assertEqual(self.ldq.first(), 'A')

    def test_last(self):
        self.assertIsNone(self.ldq.last() if self.ldq.is_empty() else None)
        self.ldq.add_last('B')
        self.assertEqual(self.ldq.last(), 'B')

    def test_add_first(self):
        self.ldq.add_first('C')
        self.assertEqual(self.ldq.first(), 'C') 

    def test_add_last(self):
        self.ldq.add_last('D')
        self.assertEqual(self.ldq.last(), 'D')

    def test_remove_first(self):
        self.assertRaises(IndexError, lambda: self.ldq.remove_first())
        self.ldq.add_first('E')
        self.assertEqual(self.ldq.remove_first(), 'E')
        self.assertTrue(self.ldq.is_empty())

    def test_remove_last(self):
        self.assertRaises(IndexError, lambda: self.ldq.remove_last())
        self.ldq.add_last('F')
        self.assertEqual(self.ldq.remove_last(), 'F')
        self.assertTrue(self.ldq.is_empty())

if __name__ == "__main__":
    unittest.main()