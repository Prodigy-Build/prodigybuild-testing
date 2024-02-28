import unittest
from typing import List


class TestSegmentTree(unittest.TestCase):
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

    def test_build(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        size = 15
        segment_tree = SegmentTree(size)
        segment_tree.build(1, 1, size, A)
        self.assertEqual(segment_tree.query(1, 1, size, 4, 6), 7)
        self.assertEqual(segment_tree.query(1, 1, size, 7, 11), 14)
        self.assertEqual(segment_tree.query(1, 1, size, 7, 12), 15)

    def test_update(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        size = 15
        segment_tree = SegmentTree(size)
        segment_tree.build(1, 1, size, A)
        segment_tree.update(1, 1, size, 1, 3, 111)
        self.assertEqual(segment_tree.query(1, 1, size, 1, 15), 111)
        segment_tree.update(1, 1, size, 7, 8, 235)
        self.assertEqual(segment_tree.query(1, 1, size, 1, 15), 235)
        self.assertEqual(
            str(segment_tree),
            "[111, 111, 111, 7, 3, -5, 235, 235, -20, 9, 14, 15, 5, 2, -8]",
        )


if __name__ == "__main__":
    unittest.main()