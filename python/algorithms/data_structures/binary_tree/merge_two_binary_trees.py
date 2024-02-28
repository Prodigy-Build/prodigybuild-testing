import unittest

class TestMergeTwoBinaryTrees(unittest.TestCase):
    def setUp(self):
        self.node1 = Node(1)
        self.node1.left = Node(2)
        self.node1.right = Node(3)
        self.node1.left.left = Node(4)

        self.node2 = Node(2)
        self.node2.left = Node(4)
        self.node2.right = Node(6)
        self.node2.left.right = Node(9)
        self.node2.right.right = Node(5)

    def test_merge_two_binary_trees(self):
        merged_tree = merge_two_binary_trees(self.node1, self.node2)
        self.assertEqual(merged_tree.value, 3)
        self.assertEqual(merged_tree.left.value, 6)
        self.assertEqual(merged_tree.right.value, 9)
        self.assertEqual(merged_tree.left.left.value, 4)
        self.assertEqual(merged_tree.left.right.value, 9)
        self.assertEqual(merged_tree.right.right.value, 5)

    def test_merge_with_None_tree(self):
        merged_tree = merge_two_binary_trees(self.node1, None)
        self.assertEqual(merged_tree.value, self.node1.value)
        self.assertEqual(merged_tree.left.value, self.node1.left.value)
        self.assertEqual(merged_tree.right.value, self.node1.right.value)
        self.assertEqual(merged_tree.left.left.value, self.node1.left.left.value)

        merged_tree = merge_two_binary_trees(None, self.node2)
        self.assertEqual(merged_tree.value, self.node2.value)
        self.assertEqual(merged_tree.left.value, self.node2.left.value)
        self.assertEqual(merged_tree.right.value, self.node2.right.value)
        self.assertEqual(merged_tree.left.right.value, self.node2.left.right.value)
        self.assertEqual(merged_tree.right.right.value, self.node2.right.right.value)

    def test_merge_both_None_trees(self):
        merged_tree = merge_two_binary_trees(None, None)
        self.assertEqual(merged_tree, None)

if __name__ == "__main__":
    unittest.main()