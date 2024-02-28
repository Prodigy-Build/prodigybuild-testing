import unittest
from random import seed

# Assuming the treap implementation is in a file named treap.py
from treap import Node, split, merge, insert, erase, inorder, interact_treap


class TestTreap(unittest.TestCase):
    
    def setUp(self):
        seed(1)  # makes the test deterministic

    def test_node(self):
        node = Node(5)
        self.assertEqual(node.value, 5)
        self.assertIsNotNone(node.prior)
        self.assertIsNone(node.left)
        self.assertIsNone(node.right)

    def test_split(self):
        root = Node(10)
        left, right = split(root, 5)
        self.assertIsNone(left)
        self.assertEqual(right.value, 10)

    def test_merge(self):
        left = Node(5)
        right = Node(10)
        root = merge(left, right)
        self.assertEqual(root.value, 5)
        self.assertEqual(root.right.value, 10)

    def test_insert(self):
        root = insert(None, 5)
        self.assertEqual(root.value, 5)

    def test_erase(self):
        root = insert(None, 5)
        root = insert(root, 10)
        root = erase(root, 5)
        self.assertEqual(root.value, 10)

    def test_inorder(self):
        root = insert(None, 5)
        root = insert(root, 10)
        root = insert(root, 2)
        vals = []
        def print_func(value):
            vals.append(value)
        inorder(root, print_func)
        self.assertEqual(vals, [2, 5, 10])

    def test_interact_treap(self):
        root = interact_treap(None, "+10")
        self.assertEqual(root.value, 10)
        root = interact_treap(root, "+5")
        self.assertEqual(root.value, 5)
        root = interact_treap(root, "-5")
        self.assertEqual(root.value, 10)


if __name__ == "__main__":
    unittest.main()