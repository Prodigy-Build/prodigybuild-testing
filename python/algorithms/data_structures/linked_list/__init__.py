from typing import Any
import unittest

class TestLinkedList(unittest.TestCase):
    def test_add(self):
        linked_list = LinkedList()
        linked_list.add(23)
        self.assertEqual(str(linked_list), "23")
        linked_list.add(14)
        self.assertEqual(str(linked_list), "14 --> 23")
        linked_list.add(9)
        self.assertEqual(str(linked_list), "9 --> 14 --> 23")

    def test_remove(self):
        linked_list = LinkedList()
        self.assertIsNone(linked_list.remove())
        linked_list.add(23)
        linked_list.add(14)
        linked_list.add(9)
        self.assertEqual(linked_list.remove(), 9)
        self.assertEqual(str(linked_list), "14 --> 23")
        self.assertEqual(linked_list.remove(), 14)
        self.assertEqual(str(linked_list), "23")
        self.assertEqual(linked_list.remove(), 23)
        self.assertEqual(str(linked_list), "")
        self.assertIsNone(linked_list.remove())

    def test_is_empty(self):
        linked_list = LinkedList()
        self.assertTrue(linked_list.is_empty())
        linked_list.add(23)
        self.assertFalse(linked_list.is_empty())
        linked_list.remove()
        self.assertTrue(linked_list.is_empty())

    def test_len(self):
        linked_list = LinkedList()
        self.assertEqual(len(linked_list), 0)
        linked_list.add("a")
        self.assertEqual(len(linked_list), 1)
        linked_list.add("b")
        self.assertEqual(len(linked_list), 2)
        linked_list.remove()
        self.assertEqual(len(linked_list), 1)
        linked_list.remove()
        self.assertEqual(len(linked_list), 0)

if __name__ == "__main__":
    unittest.main()