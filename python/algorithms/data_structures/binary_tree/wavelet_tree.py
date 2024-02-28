import unittest

class TestWaveletTree(unittest.TestCase):

    def setUp(self):
        self.test_array = [2, 1, 4, 5, 6, 0, 8, 9, 1, 2, 0, 6, 4, 2, 0, 6, 5, 3, 2, 7]
        self.root = build_tree(self.test_array)

    def test_node(self):
        node = Node(length=27)
        self.assertEqual(repr(node), 'Node(min_value=-1 max_value=-1)')

    def test_build_tree(self):
        self.assertEqual(repr(self.root), 'Node(min_value=0 max_value=9)')

    def test_rank_till_index(self):
        self.assertEqual(rank_till_index(self.root, 6, 6), 1)
        self.assertEqual(rank_till_index(self.root, 2, 0), 1)
        self.assertEqual(rank_till_index(self.root, 1, 10), 2)
        self.assertEqual(rank_till_index(self.root, 17, 7), 0)
        self.assertEqual(rank_till_index(self.root, 0, 9), 1)

    def test_rank(self):
        self.assertEqual(rank(self.root, 6, 3, 13), 2)
        self.assertEqual(rank(self.root, 2, 0, 19), 4)
        self.assertEqual(rank(self.root, 9, 2 ,2), 0)
        self.assertEqual(rank(self.root, 0, 5, 10), 2)

    def test_quantile(self):
        self.assertEqual(quantile(self.root, 2, 2, 5), 5)
        self.assertEqual(quantile(self.root, 5, 2, 13), 4)
        self.assertEqual(quantile(self.root, 0, 6, 6), 8)
        self.assertEqual(quantile(self.root, 4, 2, 5), -1)

    def test_range_counting(self):
        self.assertEqual(range_counting(self.root, 1, 10, 3, 7), 3)
        self.assertEqual(range_counting(self.root, 2, 2, 1, 4), 1)
        self.assertEqual(range_counting(self.root, 0, 19, 0, 100), 20)
        self.assertEqual(range_counting(self.root, 1, 0, 1, 100), 0)
        self.assertEqual(range_counting(self.root, 0, 17, 100, 1), 0)

if __name__ == "__main__":
    unittest.main()