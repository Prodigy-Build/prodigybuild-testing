import unittest
from avl_tree import AVLtree

class TestStringMethods(unittest.TestCase):

    def setUp(self):
        self.t = AVLtree()

    def test_empty_tree_height(self):
        self.assertEqual(0, self.t.get_height())

    def test_insertion_increasing(self):
        for i in range(5):
            self.t.insert(i)
        # Test if the tree is height balanced
        self.assertEqual(3, self.t.get_height())

    def test_insertion_decreasing(self):
        for i in range(5, 0, -1):
            self.t.insert(i)
        # Test if the tree is height balanced
        self.assertEqual(3, self.t.get_height())
        
    def test_delete_node_not_in_tree(self):
        for i in range(5, 0, -1):
            self.t.insert(i)
        self.t.del_node(10)
        self.assertEqual(3, self.t.get_height())

    def test_delete_node_in_tree(self):
        for i in range(5, 0, -1):
            self.t.insert(i)
        self.t.del_node(1)
        # Test if the tree is height balanced after deletion
        self.assertEqual(3, self.t.get_height())

if __name__ == '__main__':
    unittest.main()