import unittest

class TestBinaryTreeNodeSum(unittest.TestCase):

    def test_sum(self):
        tree = Node(10)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 10)

        tree.left = Node(5)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 15)

        tree.right = Node(-3)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 12)

        tree.left.left = Node(12)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 24)

        tree.right.left = Node(8)
        tree.right.right = Node(0)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 32)

        tree.right.right = Node(-10)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 22)

        tree.right.left.left = Node(3)
        self.assertEqual(sum(BinaryTreeNodeSum(tree)), 25)

        no_element_tree = Node(None)
        self.assertEqual(sum(BinaryTreeNodeSum(no_element_tree)), 0)


if __name__ == "__main__":
    unittest.main()