import operator
import unittest

class TestSegmentTree(unittest.TestCase):
    def setUp(self):
        self.arr = [2, 1, 5, 3, 4]
    
    def test_init(self):
        segtree = SegmentTree(self.arr, operator.add)
        self.assertIsNotNone(segtree)

    def test_update(self):
        segtree = SegmentTree(self.arr, operator.add)
        segtree.update(1, 5)
        self.assertEqual(segtree.query_range(1, 1), 5)

    def test_query_range(self):
        segtree = SegmentTree(self.arr, operator.add)
        self.assertEqual(segtree.query_range(0, 4), sum(self.arr))
        self.assertEqual(segtree.query_range(0, 1), sum(self.arr[:2]))
    
    def test_traverse(self):
        segtree = SegmentTree(self.arr, operator.add)
        self.assertIsNotNone(segtree.traverse())
    
if __name__ == "__main__":
    unittest.main()