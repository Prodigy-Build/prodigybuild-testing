import unittest

class TestSegmentTree(unittest.TestCase):
    def setUp(self):
        self.A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        self.size = 15
        self.segment_tree = SegmentTree(self.size)
        self.segment_tree.build(1, 1, self.size, self.A)

    def test_query(self):
        self.assertEqual(self.segment_tree.query(1, 1, self.size, 4, 6), 7)
        self.assertEqual(self.segment_tree.query(1, 1, self.size, 7, 11), 14)
        self.assertEqual(self.segment_tree.query(1, 1, self.size, 7, 12), 15)
    
    def test_update(self):
        self.segment_tree.update(1, 1, self.size, 1, 3, 111)
        self.assertEqual(self.segment_tree.query(1, 1, self.size, 1, 15), 111)
        self.segment_tree.update(1, 1, self.size, 7, 8, 235)
        self.assertEqual(str(self.segment_tree), str([self.segment_tree.query(1, 1, self.size, i, i) for i in range(1, self.size + 1)]))

    def test_left(self):
        segment_tree = SegmentTree(15)
        self.assertEqual(segment_tree.left(1), 2)
        self.assertEqual(segment_tree.left(2), 4)
        self.assertEqual(segment_tree.left(12), 24)
    
    def test_right(self):
        segment_tree = SegmentTree(15)
        self.assertEqual(segment_tree.right(1), 3)
        self.assertEqual(segment_tree.right(2), 5)
        self.assertEqual(segment_tree.right(12), 25)



if __name__ == '__main__':
    unittest.main()