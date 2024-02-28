import unittest

class TestLowestCommonAncestor(unittest.TestCase):

    def setUp(self):
        self.max_node = 13
        self.parent = [[0 for _ in range(self.max_node + 10)] for _ in range(20)]
        self.level = [-1 for _ in range(self.max_node + 10)]
        self.graph = {
            1: [2, 3, 4],
            2: [5],
            3: [6, 7],
            4: [8],
            5: [9, 10],
            6: [11],
            7: [],
            8: [12, 13],
            9: [],
            10: [],
            11: [],
            12: [],
            13: [],
        }
        self.level, self.parent = breadth_first_search(self.level, self.parent, self.max_node, self.graph, 1)
        self.parent = create_sparse(self.max_node, self.parent)

    def test_lowest_common_ancestor(self):
        self.assertEqual(lowest_common_ancestor(1, 3, self.level, self.parent), 1)
        self.assertEqual(lowest_common_ancestor(5, 6, self.level, self.parent), 1)
        self.assertEqual(lowest_common_ancestor(7, 11, self.level, self.parent), 1)
        self.assertEqual(lowest_common_ancestor(6, 7, self.level, self.parent), 1)
        self.assertEqual(lowest_common_ancestor(4, 12, self.level, self.parent), 4)
        self.assertEqual(lowest_common_ancestor(8, 8, self.level, self.parent), 8)

if __name__ == "__main__":
    unittest.main()