import unittest

class TestDoublyLinkedList(unittest.TestCase):
    def setUp(self):
        self.doublyLinkedList = DoublyLinkedList()

    def test_is_empty(self):
        self.assertTrue(self.doublyLinkedList.is_empty())
        self.doublyLinkedList.insert_at_tail(1)
        self.assertFalse(self.doublyLinkedList.is_empty())

    def test_insert_at_head(self):
        self.doublyLinkedList.insert_at_head(1)
        self.assertEqual(str(self.doublyLinkedList), "1")

    def test_insert_at_tail(self):
        self.doublyLinkedList.insert_at_tail(1)
        self.assertEqual(str(self.doublyLinkedList), "1")

    def test_insert_at_nth(self):
        with self.assertRaises(IndexError):
            self.doublyLinkedList.insert_at_nth(-1, 666)
        with self.assertRaises(IndexError):
            self.doublyLinkedList.insert_at_nth(1, 666)
        self.doublyLinkedList.insert_at_nth(0, 2)
        self.doublyLinkedList.insert_at_nth(0, 1)
        self.doublyLinkedList.insert_at_nth(2, 4)
        self.doublyLinkedList.insert_at_nth(2, 3)
        self.assertEqual(str(self.doublyLinkedList), "1->2->3->4")

    def test_delete_at_nth(self):
        with self.assertRaises(IndexError):
            self.doublyLinkedList.delete_at_nth(0)
        for i in range(5):
            self.doublyLinkedList.insert_at_nth(i, i + 1)
        self.assertEqual(self.doublyLinkedList.delete_at_nth(0), 1)
        self.assertEqual(self.doublyLinkedList.delete_at_nth(3), 5)
        self.assertEqual(self.doublyLinkedList.delete_at_nth(1), 3)
        self.assertEqual(str(self.doublyLinkedList), "2->4")

    def test_delete(self):
        self.doublyLinkedList.insert_at_tail(1)
        with self.assertRaises(ValueError):
            self.doublyLinkedList.delete(2)
        self.assertEqual(self.doublyLinkedList.delete(1), 1)

    def test_length(self):
        self.assertEqual(len(self.doublyLinkedList), 0)
        self.doublyLinkedList.insert_at_head(1)
        self.assertEqual(len(self.doublyLinkedList), 1)

if __name__ == '__main__':
    unittest.main()