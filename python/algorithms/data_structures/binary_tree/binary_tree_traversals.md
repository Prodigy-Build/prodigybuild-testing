import unittest
from binary_tree import BinaryTree, Node

class TestBinaryTreeTraversals(unittest.TestCase):
    def setUp(self):
        # create a binary tree
        #       1
        #      / \
        #     2   3
        #    / \ / \
        #   4  5 6  7
        self.tree = BinaryTree()
        for i in range(1, 8):
            self.tree.insert(Node(i))

    def test_pre_order_traversal(self):
        self.assertEqual(self.tree.pre_order_traversal(self.tree.root), [1, 2, 4, 5, 3, 6, 7])

    def test_in_order_traversal(self):
        self.assertEqual(self.tree.in_order_traversal(self.tree.root), [4, 2, 5, 1, 6, 3, 7])
        
    def test_post_order_traversal(self):
        self.assertEqual(self.tree.post_order_traversal(self.tree.root), [4, 5, 2, 6, 7, 3, 1])

    def test_level_order_traversal(self):
        self.assertEqual(self.tree.level_order_traversal(self.tree.root), [1, 2, 3, 4, 5, 6, 7])

if __name__ == '__main__':
    unittest.main()