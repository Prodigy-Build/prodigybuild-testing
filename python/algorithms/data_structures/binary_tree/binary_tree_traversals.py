import unittest

class TestBinaryTree(unittest.TestCase):
    def setUp(self):
        self.root = make_tree()

    def test_preorder(self):
        self.assertEqual(preorder(self.root), [1, 2, 4, 5, 3])

    def test_postorder(self):
        self.assertEqual(postorder(self.root), [4, 5, 2, 3, 1])

    def test_inorder(self):
        self.assertEqual(inorder(self.root), [4, 2, 5, 1, 3])

    def test_height(self):
        self.assertEqual(height(self.root), 3)

    def test_level_order(self):
        self.assertEqual(level_order(self.root), [1, 2, 3, 4, 5])

    def test_get_nodes_from_left_to_right(self):
        self.assertEqual(get_nodes_from_left_to_right(self.root, 2), [2, 3])

    def test_get_nodes_from_right_to_left(self):
        self.assertEqual(get_nodes_from_right_to_left(self.root, 2), [3, 2])

    def test_zigzag(self):
        self.assertEqual(zigzag(self.root), [[1], [3, 2], [4, 5]])

if __name__ == "__main__":
    unittest.main()