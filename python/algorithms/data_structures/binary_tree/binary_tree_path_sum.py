```python
import unittest
from algorithms.data_structures.binary_tree.binary_tree_path_sum import Node, BinaryTreePathSum

class TestBinaryTreePathSum(unittest.TestCase):
    def test_path_sum(self):
        # Create the binary tree
        tree = Node(10)
        tree.left = Node(5)
        tree.right = Node(-3)
        tree.left.left = Node(3)
        tree.left.right = Node(2)
        tree.right.right = Node(11)
        tree.left.left.left = Node(3)
        tree.left.left.right = Node(-2)
        tree.left.right.right = Node(1)

        # Create an instance of BinaryTreePathSum
        btps = BinaryTreePathSum()

        # Test case 1: target = 8
        self.assertEqual(btps.path_sum(tree, 8), 3)

        # Test case 2: target = 7
        self.assertEqual(btps.path_sum(tree, 7), 2)

        # Test case 3: target = 8 (after modifying the tree)
        tree.right.right = Node(10)
        self.assertEqual(btps.path_sum(tree, 8), 2)

if __name__ == "__main__":
    unittest.main()
```