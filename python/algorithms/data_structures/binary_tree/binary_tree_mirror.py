import unittest


class TestBinaryTreeMirror(unittest.TestCase):

    def test_binary_tree_mirror(self):
        
        binary_tree = {1: [2, 3], 2: [4, 5], 3: [6, 7], 7: [8, 9]}
        self.assertEqual(binary_tree_mirror(binary_tree, 1), {1: [3, 2], 2: [5, 4], 3: [7, 6], 7: [9, 8]})

        binary_tree = {1: [2, 3], 2: [4, 5], 3: [6, 7], 4: [10, 11]}
        self.assertEqual(binary_tree_mirror(binary_tree, 1), {1: [3, 2], 2: [5, 4], 3: [7, 6], 4: [11, 10]})
        
        with self.assertRaises(ValueError):
            binary_tree = {1: [2, 3], 2: [4, 5], 3: [6, 7], 4: [10, 11]}
            binary_tree_mirror(binary_tree, 5)
            
        with self.assertRaises(ValueError):
            binary_tree = {}
            binary_tree_mirror(binary_tree, 5)


if __name__ == "__main__":
    unittest.main()