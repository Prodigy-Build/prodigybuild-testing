```python
# python/algorithms/data_structures/binary_tree/binary_search_tree.py

import unittest
from binary_search_tree import BinarySearchTree, Node

class BinarySearchTreeTestCase(unittest.TestCase):
    def setUp(self):
        self.tree = BinarySearchTree()
        self.tree.insert(8, 3, 6, 1, 10, 14, 13, 4, 7)

    def test_insert(self):
        self.assertEqual(str(self.tree), "8\n {'3': (1, {'6': (4, 7)})} {'10': (None, {'14': (13, None)})}")

    def test_search(self):
        self.assertIsNotNone(self.tree.search(6))
        self.assertIsNone(self.tree.search(0))

    def test_get_max(self):
        self.assertEqual(self.tree.get_max().value, 14)

    def test_get_min(self):
        self.assertEqual(self.tree.get_min().value, 1)

    def test_remove(self):
        self.tree.remove(6)
        self.assertIsNone(self.tree.search(6))

    def test_traversal_tree(self):
        self.assertEqual([node.value for node in self.tree.traversal_tree()], [8, 3, 1, 6, 4, 7, 10, 14, 13])

    def test_find_kth_smallest(self):
        self.assertEqual(self.tree.find_kth_smallest(3, self.tree.root), 3)

    def test_postorder(self):
        self.assertEqual([node.value for node in postorder(self.tree.root)], [1, 4, 7, 6, 3, 13, 14, 10, 8])

if __name__ == "__main__":
    unittest.main()
```