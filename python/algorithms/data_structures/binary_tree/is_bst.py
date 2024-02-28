import unittest
from is_bst import TreeNode, is_binary_search_tree


class TestIsBst(unittest.TestCase):
    def setUp(self):
        self.node1 = TreeNode(2, TreeNode(1), TreeNode(3))
        self.node2 = TreeNode(5, TreeNode(1), TreeNode(4))
        self.node3 = TreeNode(2, TreeNode('c'), TreeNode(3))
        self.node4 = None

    def test_is_bst(self):
        self.assertEqual(is_binary_search_tree(self.node1), True)
        self.assertEqual(is_binary_search_tree(self.node2), False)
        with self.assertRaises(ValueError):
            is_binary_search_tree(self.node3)
        self.assertEqual(is_binary_search_tree(self.node4), True)


if __name__ == "__main__":
    unittest.main()