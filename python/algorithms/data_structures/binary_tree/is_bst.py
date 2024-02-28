```python
from typing import Union
import unittest

class TreeNode:
    def __init__(self, data: Union[float, str]) -> None:
        self.data = data
        self.left = None
        self.right = None

def is_binary_search_tree(root: TreeNode) -> bool:
    def is_valid_tree(node: TreeNode) -> bool:
        if node is None:
            return True

        if not isinstance(node, TreeNode):
            return False

        try:
            float(node.data)
        except (TypeError, ValueError):
            return False

        return is_valid_tree(node.left) and is_valid_tree(node.right)

    if not is_valid_tree(root):
        raise ValueError(
            "Each node should be type of TreeNode and data should be float."
        )

    def is_binary_search_tree_recursive_check(
        node: TreeNode, left_bound: float, right_bound: float
    ) -> bool:
        if node is None:
            return True

        return (
            left_bound < node.data < right_bound
            and is_binary_search_tree_recursive_check(node.left, left_bound, node.data)
            and is_binary_search_tree_recursive_check(
                node.right, node.data, right_bound
            )
        )

    return is_binary_search_tree_recursive_check(root, -float("inf"), float("inf"))

class TestIsBinarySearchTree(unittest.TestCase):
    def test_is_binary_search_tree(self):
        # Test case 1
        root1 = TreeNode(2)
        root1.left = TreeNode(1)
        root1.right = TreeNode(3)
        self.assertTrue(is_binary_search_tree(root1))

        # Test case 2
        root2 = TreeNode(0)
        root2.left = TreeNode(-11)
        root2.right = TreeNode(3)
        self.assertTrue(is_binary_search_tree(root2))

        # Test case 3
        root3 = TreeNode(5)
        root3.left = TreeNode(1)
        root3.right = TreeNode(4)
        root3.right.left = TreeNode(3)
        self.assertFalse(is_binary_search_tree(root3))

        # Test case 4
        root4 = TreeNode('a')
        root4.left = TreeNode(1)
        root4.right = TreeNode(4)
        root4.right.left = TreeNode(3)
        with self.assertRaises(ValueError):
            is_binary_search_tree(root4)

        # Test case 5
        root5 = TreeNode(2)
        root5.left = TreeNode([])
        root5.right = TreeNode(4)
        root5.right.left = TreeNode(3)
        with self.assertRaises(ValueError):
            is_binary_search_tree(root5)

if __name__ == "__main__":
    unittest.main()
```