import unittest

class TestBinaryTreeMethods(unittest.TestCase):
    
    def setUp(self):
        """Set up a binary tree for testing"""
        self.tree = Node(1)
        self.tree.left = Node(2)
        self.tree.right = Node(3)
        self.tree.left.left = Node(4)
        self.tree.left.right = Node(5)
        self.tree.left.right.left = Node(6)
        self.tree.right.left = Node(7)
        self.tree.right.left.left = Node(8)
        self.tree.right.left.left.right = Node(9)
    
    def test_depth_of_tree(self):
        """Test the depth_of_tree function"""
        self.assertEqual(depth_of_tree(self.tree), 5)
        self.assertEqual(depth_of_tree(self.tree.left), 4)
        self.assertEqual(depth_of_tree(self.tree.right), 3)

    def test_is_full_binary_tree(self):
        """Test the is_full_binary_tree function"""
        self.assertFalse(is_full_binary_tree(self.tree))
        
        full_tree = Node(1)
        full_tree.left = Node(2)
        full_tree.right = Node(3)
        self.assertTrue(is_full_binary_tree(full_tree))

if __name__ == '__main__':
    unittest.main()