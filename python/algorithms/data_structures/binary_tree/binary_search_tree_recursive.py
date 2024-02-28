"""
Unit test cases for the original file
"""
import unittest
from binary_search_tree_recursive import BinarySearchTree, Node


class NodeTestCase(unittest.TestCase):
    def test_node_creation(self):
        parent = Node(1, None)
        node = Node(5, parent)

        self.assertEqual(node.label, 5)
        self.assertEqual(node.parent, parent)
        self.assertEqual(node.left, None)
        self.assertEqual(node.right, None)


class BinarySearchTreeTestCase(unittest.TestCase):
    def test_empty(self):
        tree = BinarySearchTree()

        self.assertIs(tree.root, None)

    def test_put(self):
        tree = BinarySearchTree()
        tree.put(5)

        self.assertIsInstance(tree.root, Node)
        self.assertEqual(tree.root.label, 5)

    def test_search(self):
        tree = BinarySearchTree()
        tree.put(5)
        tree.put(10)
        tree.put(3)

        found_node = tree.search(10)

        self.assertIsInstance(found_node, Node)
        self.assertEqual(found_node.label, 10)

    def test_remove(self):
        tree = BinarySearchTree()
        tree.put(5)
        tree.put(10)
        tree.put(3)
        tree.remove(10)

        with self.assertRaises(Exception) as context:
            tree.search(10)
        
        self.assertEqual(str(context.exception), 'Node with label 10 does not exist')


if __name__ == '__main__':
    unittest.main()