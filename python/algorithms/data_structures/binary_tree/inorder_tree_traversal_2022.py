"""
Unit test cases for the binary trees
"""

import unittest
from inorder_tree_traversal_2022 import BinaryTreeNode, insert, inorder

class TestBinaryTree(unittest.TestCase):

    def setUp(self):
        self.root = BinaryTreeNode(15)
        insert(self.root, 10)
        insert(self.root, 25)
        insert(self.root, 6)
        insert(self.root, 14)
        insert(self.root, 20)
        insert(self.root, 60)
    
    def test_insert(self):
        # Checking if the node has been inserted at the correct position
        node50 =  insert(self.root, 50)
        self.assertEqual(node50.right_child.right_child.data, 50)

    def test_inorder(self):
        # Checking if inorder traversal is returning correct array
        self.assertEqual(inorder(self.root), [6, 10, 14, 15, 20, 25, 60])

if __name__ == "__main__":
    unittest.main()