```python
import unittest
from algorithms.data_structures.binary_tree.diff_views_of_binary_tree import (
    TreeNode,
    make_tree,
    binary_tree_right_side_view,
    binary_tree_left_side_view,
    binary_tree_top_side_view,
    binary_tree_bottom_side_view,
)


class TestBinaryTreeViews(unittest.TestCase):
    def test_binary_tree_right_side_view(self):
        root = make_tree()
        expected = [3, 20, 7]
        self.assertEqual(binary_tree_right_side_view(root), expected)

        root = None
        expected = []
        self.assertEqual(binary_tree_right_side_view(root), expected)

    def test_binary_tree_left_side_view(self):
        root = make_tree()
        expected = [3, 9, 15]
        self.assertEqual(binary_tree_left_side_view(root), expected)

        root = None
        expected = []
        self.assertEqual(binary_tree_left_side_view(root), expected)

    def test_binary_tree_top_side_view(self):
        root = make_tree()
        expected = [9, 3, 20, 7]
        self.assertEqual(binary_tree_top_side_view(root), expected)

        root = None
        expected = []
        self.assertEqual(binary_tree_top_side_view(root), expected)

    def test_binary_tree_bottom_side_view(self):
        root = make_tree()
        expected = [9, 15, 20, 7]
        self.assertEqual(binary_tree_bottom_side_view(root), expected)

        root = None
        expected = []
        self.assertEqual(binary_tree_bottom_side_view(root), expected)


if __name__ == "__main__":
    unittest.main()
```