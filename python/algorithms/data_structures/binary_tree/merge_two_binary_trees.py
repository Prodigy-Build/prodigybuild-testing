```python
import unittest

from algorithms.data_structures.binary_tree.merge_two_binary_trees import Node, merge_two_binary_trees, print_preorder


class TestMergeTwoBinaryTrees(unittest.TestCase):
    def test_merge_two_binary_trees(self):
        # Create tree1
        tree1 = Node(5)
        tree1.left = Node(6)
        tree1.right = Node(7)
        tree1.left.left = Node(2)

        # Create tree2
        tree2 = Node(4)
        tree2.left = Node(5)
        tree2.right = Node(8)
        tree2.left.right = Node(1)
        tree2.right.right = Node(4)

        # Merge tree1 and tree2
        merged_tree = merge_two_binary_trees(tree1, tree2)

        # Expected merged tree
        expected_tree = Node(9)
        expected_tree.left = Node(11)
        expected_tree.left.left = Node(2)
        expected_tree.left.right = Node(1)
        expected_tree.right = Node(15)
        expected_tree.right.right = Node(4)

        # Compare the merged tree with the expected tree
        self.assertEqual(print_preorder(merged_tree), print_preorder(expected_tree))


if __name__ == "__main__":
    unittest.main()
```