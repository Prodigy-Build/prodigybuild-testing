import unittest

class TestBinarySearchTree(unittest.TestCase):

    def setUp(self):
        self.tree = BinarySearchTree()
        self.values = [8, 3, 6, 1, 10, 14, 13, 4, 7]
        for value in self.values:
            self.tree.insert(value)

    def test_insert(self):
        self.tree.insert(15)
        node = self.tree.search(15)
        self.assertEqual(node.value, 15)

    def test_search(self):
        node = self.tree.search(14)
        self.assertEqual(node.value, 14)
        self.assertTrue(self.tree.is_right(node))

    def test_get_max(self):
        max_node = self.tree.get_max()
        self.assertEqual(max_node.value, max(self.values))

    def test_get_min(self):
        min_node = self.tree.get_min()
        self.assertEqual(min_node.value, min(self.values))

    def test_remove(self):
        self.tree.remove(3)
        node = self.tree.search(3)
        self.assertIsNone(node)

    def test_find_kth_smallest(self):
        kth_smallest = self.tree.find_kth_smallest(3, self.tree.root)
        self.assertEqual(kth_smallest, sorted(self.values)[2])

    def test_preorder_traverse(self):
        pre_order = list(self.tree.preorder_traverse(self.tree.root))
        self.assertTrue(all(isinstance(node, Node) for node in pre_order))

    def test_traversal_tree(self):
        traversal = list(self.tree.traversal_tree())
        self.assertTrue(all(isinstance(node, Node) for node in traversal))


if __name__ == "__main__":
    unittest.main()