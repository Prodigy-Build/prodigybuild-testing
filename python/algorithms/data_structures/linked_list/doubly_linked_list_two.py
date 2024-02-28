```python
import unittest
from algorithms.data_structures.linked_list.doubly_linked_list_two import LinkedList, Node


class TestLinkedList(unittest.TestCase):
    def setUp(self):
        self.linked_list = LinkedList()

    def test_create_linked_list(self):
        self.assertIsNone(self.linked_list.get_head_data())
        self.assertIsNone(self.linked_list.get_tail_data())
        self.assertTrue(self.linked_list.is_empty())

        self.linked_list.insert(10)
        self.assertEqual(self.linked_list.get_head_data(), 10)
        self.assertEqual(self.linked_list.get_tail_data(), 10)

        self.linked_list.insert_at_position(position=3, value=20)
        self.assertEqual(self.linked_list.get_head_data(), 10)
        self.assertEqual(self.linked_list.get_tail_data(), 20)

        self.linked_list.set_head(Node(1000))
        self.assertEqual(self.linked_list.get_head_data(), 1000)
        self.assertEqual(self.linked_list.get_tail_data(), 20)

        self.linked_list.set_tail(Node(2000))
        self.assertEqual(self.linked_list.get_head_data(), 1000)
        self.assertEqual(self.linked_list.get_tail_data(), 2000)

        values = [node_data for node_data in self.linked_list]
        self.assertEqual(values, [1000, 10, 20, 2000])
        self.assertFalse(self.linked_list.is_empty())

        values = [node_data for node_data in self.linked_list]
        self.assertEqual(values, [1000, 10, 20, 2000])
        self.assertTrue(10 in self.linked_list)

        self.linked_list.delete_value(value=10)
        self.assertFalse(10 in self.linked_list)

        self.linked_list.delete_value(value=2000)
        self.assertEqual(self.linked_list.get_tail_data(), 20)

        self.linked_list.delete_value(value=1000)
        self.assertEqual(self.linked_list.get_tail_data(), 20)
        self.assertEqual(self.linked_list.get_head_data(), 20)

        values = [node_data for node_data in self.linked_list]
        self.assertEqual(values, [20])

        self.linked_list.delete_value(value=20)
        values = [node_data for node_data in self.linked_list]
        self.assertEqual(values, [])

        for value in range(1, 10):
            self.linked_list.insert(value=value)

        values = [node_data for node_data in self.linked_list]
        self.assertEqual(values, [1, 2, 3, 4, 5, 6, 7, 8, 9])


if __name__ == "__main__":
    unittest.main()
```