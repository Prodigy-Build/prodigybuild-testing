from __future__ import annotations

from typing import Any
import unittest


class ContainsLoopError(Exception):
    pass


class Node:
    def __init__(self, data: Any) -> None:
        self.data: Any = data
        self.next_node: Node | None = None

    def __iter__(self):
        node = self
        visited = []
        while node:
            if node in visited:
                raise ContainsLoopError
            visited.append(node)
            yield node.data
            node = node.next_node

    @property
    def has_loop(self) -> bool:
        """
        A loop is when the exact same Node appears more than once in a linked list.
        >>> root_node = Node(1)
        >>> root_node.next_node = Node(2)
        >>> root_node.next_node.next_node = Node(3)
        >>> root_node.next_node.next_node.next_node = Node(4)
        >>> root_node.has_loop
        False
        >>> root_node.next_node.next_node.next_node = root_node.next_node
        >>> root_node.has_loop
        True
        """
        try:
            list(self)
            return False
        except ContainsLoopError:
            return True


class TestNode(unittest.TestCase):
    def test_has_loop(self):
        root_node = Node(1)
        root_node.next_node = Node(2)
        root_node.next_node.next_node = Node(3)
        root_node.next_node.next_node.next_node = Node(4)
        self.assertFalse(root_node.has_loop)

        root_node.next_node.next_node.next_node = root_node.next_node
        self.assertTrue(root_node.has_loop)

        root_node = Node(5)
        root_node.next_node = Node(6)
        root_node.next_node.next_node = Node(5)
        root_node.next_node.next_node.next_node = Node(6)
        self.assertFalse(root_node.has_loop)

        root_node = Node(1)
        self.assertFalse(root_node.has_loop)


if __name__ == "__main__":
    unittest.main()