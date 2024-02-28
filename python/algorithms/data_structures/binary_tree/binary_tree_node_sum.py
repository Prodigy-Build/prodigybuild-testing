```python
import unittest
from algorithms.data_structures.binary_tree.binary_tree_node_sum import Node, BinaryTreeNodeSum

class TestBinaryTreeNodeSum(unittest.TestCase):
    def test_sum(self):
        # Create the tree
        tree = Node(10)
        tree.left = Node(5)
        tree.right = Node(-3)
        tree.left.left = Node(12)
        tree.right.left = Node(8)
        tree.right.right = Node(0)

        # Create the BinaryTreeNodeSum object
        binary_tree_node_sum = BinaryTreeNodeSum(tree)

        # Test the sum method
        self.assertEqual(sum(binary_tree_node_sum), 32)

if __name__ == "__main__":
    unittest.main()
```