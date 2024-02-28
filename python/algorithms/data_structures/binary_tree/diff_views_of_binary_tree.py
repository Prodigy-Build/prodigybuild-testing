import unittest

class TestDiffViewsOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self.root = make_tree()

    def test_make_tree(self):
        self.assertEqual(self.root.val, 3)
        self.assertEqual(self.root.left.val, 9)
        self.assertEqual(self.root.right.val, 20)
        self.assertEqual(self.root.right.left.val, 15)
        self.assertEqual(self.root.right.right.val, 7)

    def test_binary_tree_right_side_view(self):
        self.assertEqual(binary_tree_right_side_view(self.root), [3, 20, 7])
        self.assertEqual(binary_tree_right_side_view(None), [])

    def test_binary_tree_left_side_view(self):
        self.assertEqual(binary_tree_left_side_view(self.root), [3, 9, 15])
        self.assertEqual(binary_tree_left_side_view(None), [])

    def test_binary_tree_top_side_view(self):
        self.assertEqual(binary_tree_top_side_view(self.root), [9, 3, 20, 7])
        self.assertEqual(binary_tree_top_side_view(None), [])

    def test_binary_tree_bottom_side_view(self):
        self.assertEqual(binary_tree_bottom_side_view(self.root), [9, 15, 20, 7])
        self.assertEqual(binary_tree_bottom_side_view(None), [])

if __name__ == "__main__":
    unittest.main()