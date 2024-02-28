from typing import Any
import unittest


class Node:
    def __init__(self, data: Any):
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return f"Node({self.data})"


class LinkedList:
    def __init__(self):
        self.head = None

    def __iter__(self) -> Any:
        node = self.head
        while node:
            yield node.data
            node = node.next

    def __len__(self) -> int:
        return sum(1 for _ in self)

    def __repr__(self) -> str:
        return "->".join([str(item) for item in self])

    def __getitem__(self, index: int) -> Any:
        if not 0 <= index < len(self):
            raise ValueError("list index out of range.")
        for i, node in enumerate(self):
            if i == index:
                return node
        return None

    def __setitem__(self, index: int, data: Any) -> None:
        if not 0 <= index < len(self):
            raise ValueError("list index out of range.")
        current = self.head
        for _ in range(index):
            current = current.next
        current.data = data

    def insert_tail(self, data: Any) -> None:
        self.insert_nth(len(self), data)

    def insert_head(self, data: Any) -> None:
        self.insert_nth(0, data)

    def insert_nth(self, index: int, data: Any) -> None:
        if not 0 <= index <= len(self):
            raise IndexError("list index out of range")
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        elif index == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            temp = self.head
            for _ in range(index - 1):
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node

    def print_list(self) -> None:
        print(self)

    def delete_head(self) -> Any:
        return self.delete_nth(0)

    def delete_tail(self) -> Any:
        return self.delete_nth(len(self) - 1)

    def delete_nth(self, index: int = 0) -> Any:
        if not 0 <= index <= len(self) - 1:
            raise IndexError("List index out of range.")
        delete_node = self.head
        if index == 0:
            self.head = self.head.next
        else:
            temp = self.head
            for _ in range(index - 1):
                temp = temp.next
            delete_node = temp.next
            temp.next = temp.next.next
        return delete_node.data

    def is_empty(self) -> bool:
        return self.head is None

    def reverse(self) -> None:
        prev = None
        current = self.head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev


class TestSinglyLinkedList(unittest.TestCase):
    def test_insert_tail(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        self.assertEqual(str(linked_list), "1->2->3")

    def test_insert_head(self):
        linked_list = LinkedList()
        linked_list.insert_head(1)
        linked_list.insert_head(2)
        linked_list.insert_head(3)
        self.assertEqual(str(linked_list), "3->2->1")

    def test_insert_nth(self):
        linked_list = LinkedList()
        linked_list.insert_nth(0, 1)
        linked_list.insert_nth(1, 2)
        linked_list.insert_nth(2, 3)
        self.assertEqual(str(linked_list), "1->2->3")

    def test_delete_head(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        linked_list.delete_head()
        self.assertEqual(str(linked_list), "2->3")

    def test_delete_tail(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        linked_list.delete_tail()
        self.assertEqual(str(linked_list), "1->2")

    def test_delete_nth(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        linked_list.delete_nth(1)
        self.assertEqual(str(linked_list), "1->3")

    def test_is_empty(self):
        linked_list = LinkedList()
        self.assertTrue(linked_list.is_empty())
        linked_list.insert_head(1)
        self.assertFalse(linked_list.is_empty())

    def test_reverse(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        linked_list.reverse()
        self.assertEqual(str(linked_list), "3->2->1")

    def test_len(self):
        linked_list = LinkedList()
        self.assertEqual(len(linked_list), 0)
        linked_list.insert_tail(1)
        self.assertEqual(len(linked_list), 1)
        linked_list.insert_head(2)
        self.assertEqual(len(linked_list), 2)
        linked_list.delete_tail()
        self.assertEqual(len(linked_list), 1)
        linked_list.delete_head()
        self.assertEqual(len(linked_list), 0)

    def test_getitem(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        self.assertEqual(linked_list[0], 1)
        self.assertEqual(linked_list[1], 2)
        self.assertEqual(linked_list[2], 3)

    def test_setitem(self):
        linked_list = LinkedList()
        linked_list.insert_tail(1)
        linked_list.insert_tail(2)
        linked_list.insert_tail(3)
        linked_list[0] = 4
        linked_list[1] = 5
        linked_list[2] = 6
        self.assertEqual(str(linked_list), "4->5->6")


if __name__ == "__main__":
    unittest.main()