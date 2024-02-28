import unittest

class TestBinaryTreePathSum(unittest.TestCase):
    def setUp(self):
        """
        Set up a binary tree for test cases.
        """
        self.tree = Node(10)
        self.tree.left = Node(5)
        self.tree.right = Node(-3)
        self.tree.left.left = Node(3)
        self.tree.left.right = Node(2)
        self.tree.right.right = Node(11)
        self.tree.left.left.left = Node(3)
        self.tree.left.left.right = Node(-2)
        self.tree.left.right.right = Node(1)
        self.path_sum_obj = BinaryTreePathSum()

    def test_path_sum(self):
        """
        Test path_sum method.
        """
        result = self.path_sum_obj.path_sum(self.tree, 8)
        self.assertEqual(result, 3)

        result = self.path_sum_obj.path_sum(self.tree, 7)
        self.assertEqual(result, 2)

        self.tree.right.right = Node(10)
        result = self.path_sum_obj.path_sum(self.tree, 8)
        self.assertEqual(result, 2)

    def test_path_sum_return_zero_when_tree_is_none(self):
        """
        Test path_sum method handles tree is None edge case.
        """
        result = self.path_sum_obj.path_sum(None, 8)
        self.assertEqual(result, 0)


if __name__ == "__main__":
    unittest.main()