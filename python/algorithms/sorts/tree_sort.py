import unittest

class TestTreeSort(unittest.TestCase):

    def test_tree_sort(self):
        self.assertEqual(tree_sort([10, 1, 3, 2, 9, 14, 13]), [1, 2, 3, 9, 10, 13, 14])
        self.assertEqual(tree_sort([]), [])
        self.assertEqual(tree_sort([1,1,1,1,1]), [1,1,1,1,1])
        self.assertEqual(tree_sort([100,5,3,9,16,35,2]), [2,3,5,9,16,35,100])

    def test_inorder(self):
        root = Node(10)
        for i in [1, 3, 2, 9, 14, 13]:
            root.insert(i)
        res = []
        inorder(root, res)
        self.assertEqual(res, [1, 2, 3, 9, 10, 13, 14])


if __name__ == "__main__":
    unittest.main()