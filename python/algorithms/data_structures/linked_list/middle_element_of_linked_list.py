from __future__ import annotations

import unittest


class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data: int) -> int:
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
        return self.head.data

    def middle_element(self) -> int | None:
        slow_pointer = self.head
        fast_pointer = self.head
        if self.head:
            while fast_pointer and fast_pointer.next:
                fast_pointer = fast_pointer.next.next
                slow_pointer = slow_pointer.next
            return slow_pointer.data
        else:
            print("No element found.")
            return None


class TestLinkedList(unittest.TestCase):
    def test_middle_element_empty_list(self):
        link = LinkedList()
        self.assertIsNone(link.middle_element())

    def test_middle_element_single_element(self):
        link = LinkedList()
        link.push(5)
        self.assertEqual(link.middle_element(), 5)

    def test_middle_element_odd_elements(self):
        link = LinkedList()
        link.push(5)
        link.push(6)
        link.push(8)
        link.push(8)
        link.push(10)
        link.push(12)
        link.push(17)
        link.push(7)
        link.push(3)
        link.push(20)
        link.push(-20)
        self.assertEqual(link.middle_element(), 12)

    def test_middle_element_even_elements(self):
        link = LinkedList()
        link.push(5)
        link.push(6)
        link.push(8)
        link.push(8)
        link.push(10)
        link.push(12)
        link.push(17)
        link.push(7)
        link.push(3)
        link.push(20)
        self.assertEqual(link.middle_element(), 7)


if __name__ == "__main__":
    unittest.main()