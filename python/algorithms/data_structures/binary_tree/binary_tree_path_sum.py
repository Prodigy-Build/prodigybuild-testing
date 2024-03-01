```python
from typing import Optional
import unittest

class Node:
    """
    A Node has value variable and pointers to Nodes to its left and right.
    """

    def __init__(self, value: int) -> None:
        self.value = value
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None


class BinaryTreePathSum:
    r"""
    The below tree looks like this
          10
         /  \
        5   -3
       / \    \
      3   2    11
     / \   \
    3  -2   1
    """

    target: int

    def __init__(self) -> None:
        self.paths = 0

    def depth_first_search(self, node: Optional[Node], path_sum: int) -> None:
        if node is None:
            return

        if path_sum == self.target:
            self.paths += 1

        if node.left:
            self.depth_first_search(node.left, path_sum + node.left.value)
        if node.right:
            self.depth_first_search(node.right, path_sum + node.right.value)

    def path_sum(self, node: Optional[Node], target: Optional[int] = None) -> int:
        if node is None:
            return 0
        if target is not None:
            self.target = target

        self.depth_first_search(node, node.value)
        self.path_sum(node.left)
        self.path_sum(node.right)

        return self.paths


class TestBinaryTreePathSum(unittest.TestCase):
    def test_path_sum(self):
        tree = Node(10)
        tree.left = Node(5)
        tree.right = Node(-3)
        tree.left.left = Node(3)
        tree.left.right = Node(2)
        tree.right.right = Node(11)
        tree.left.left.left = Node(3)
        tree.left.left.right = Node(-2)
        tree.left.right.right = Node(1)

        self.assertEqual(BinaryTreePathSum().path_sum(tree, 8), 3)
        self.assertEqual(BinaryTreePathSum().path_sum(tree, 7), 2)
        tree.right.right = Node(10)
        self.assertEqual(BinaryTreePathSum().path_sum(tree, 8), 2)


if __name__ == "__main__":
    unittest.main()
```