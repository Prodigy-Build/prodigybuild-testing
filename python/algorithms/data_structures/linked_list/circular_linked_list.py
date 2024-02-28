import unittest

class TestCircularLinkedList(unittest.TestCase):
    def setUp(self):
        self.circular_linked_list = CircularLinkedList()

    def test_len(self):
        self.assertEqual(len(self.circular_linked_list), 0)

    def test_is_empty(self):
        self.assertTrue(self.circular_linked_list.is_empty())
        
    def test_insert_head(self):
        self.circular_linked_list.insert_head(1)
        self.assertEqual(str(self.circular_linked_list), '1')
        
    def test_insert_tail(self):
        self.circular_linked_list.insert_tail(1)
        self.assertEqual(str(self.circular_linked_list), '1')

    def test_insert_nth(self):
        with self.assertRaises(IndexError):
            self.circular_linked_list.insert_nth(1, 1)

    def test_delete_front(self):
        with self.assertRaises(IndexError):
            self.circular_linked_list.delete_front()

    def test_delete_tail(self):
        with self.assertRaises(IndexError):
            self.circular_linked_list.delete_tail() 

    def test_delete_nth(self):
        with self.assertRaises(IndexError):
            self.circular_linked_list.delete_nth(0)

    def test_delete_add_delete(self):
        for i in range(5):
            self.assertEqual(len(self.circular_linked_list), i)
            self.circular_linked_list.insert_nth(i, i + 1)
        self.circular_linked_list.insert_tail(6)
        self.circular_linked_list.insert_head(0)
        self.assertEqual(self.circular_linked_list.delete_front(), 0)
        self.assertEqual(self.circular_linked_list.delete_tail(), 6)
        self.assertEqual(self.circular_linked_list.delete_nth(2), 3)
        self.circular_linked_list.insert_nth(2, 3)
        self.assertFalse(self.circular_linked_list.is_empty())

if __name__ == "__main__":
    unittest.main()