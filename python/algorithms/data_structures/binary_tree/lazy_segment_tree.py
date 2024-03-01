from __future__ import annotations

import math
import unittest


class SegmentTree:
    def __init__(self, size: int) -> None:
        self.size = size
        # approximate the overall size of segment tree with given value
        self.segment_tree = [0 for i in range(0, 4 * size)]
        # create array to store lazy update
        self.lazy = [0 for i in range(0, 4 * size)]
        self.flag = [0 for i in range(0, 4 * size)]  # flag for lazy update

    def left(self, idx: int) -> int:
        return idx * 2

    def right(self, idx: int) -> int:
        return idx * 2 + 1

    def build(
        self, idx: int, left_element: int, right_element: int, a: list[int]
    ) -> None:
        if left_element == right_element:
            self.segment_tree[idx] = a[left_element - 1]
        else:
            mid = (left_element + right_element) // 2
            self.build(self.left(idx), left_element, mid, a)
            self.build(self.right(idx), mid + 1, right_element, a)
            self.segment_tree[idx] = max(
                self.segment_tree[self.left(idx)], self.segment_tree[self.right(idx)]
            )

    def update(
        self, idx: int, left_element: int, right_element: int, a: int, b: int, val: int
    ) -> bool:
        if self.flag[idx] is True:
            self.segment_tree[idx] = self.lazy[idx]
            self.flag[idx] = False
            if left_element != right_element:
                self.lazy[self.left(idx)] = self.lazy[idx]
                self.lazy[self.right(idx)] = self.lazy[idx]
                self.flag[self.left(idx)] = True
                self.flag[self.right(idx)] = True

        if right_element < a or left_element > b:
            return True
        if left_element >= a and right_element <= b:
            self.segment_tree[idx] = val
            if left_element != right_element:
                self.lazy[self.left(idx)] = val
                self.lazy[self.right(idx)] = val
                self.flag[self.left(idx)] = True
                self.flag[self.right(idx)] = True
            return True
        mid = (left_element + right_element) // 2
        self.update(self.left(idx), left_element, mid, a, b, val)
        self.update(self.right(idx), mid + 1, right_element, a, b, val)
        self.segment_tree[idx] = max(
            self.segment_tree[self.left(idx)], self.segment_tree[self.right(idx)]
        )
        return True

    def query(
        self, idx: int, left_element: int, right_element: int, a: int, b: int
    ) -> int | float:
        if self.flag[idx] is True:
            self.segment_tree[idx] = self.lazy[idx]
            self.flag[idx] = False
            if left_element != right_element:
                self.lazy[self.left(idx)] = self.lazy[idx]
                self.lazy[self.right(idx)] = self.lazy[idx]
                self.flag[self.left(idx)] = True
                self.flag[self.right(idx)] = True
        if right_element < a or left_element > b:
            return -math.inf
        if left_element >= a and right_element <= b:
            return self.segment_tree[idx]
        mid = (left_element + right_element) // 2
        q1 = self.query(self.left(idx), left_element, mid, a, b)
        q2 = self.query(self.right(idx), mid + 1, right_element, a, b)
        return max(q1, q2)

    def __str__(self) -> str:
        return str([self.query(1, 1, self.size, i, i) for i in range(1, self.size + 1)])


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
        segment_tree = SegmentTree(15)
        segment_tree.build(1, 1, 15, A)
        self.assertEqual(segment_tree.query(1, 1, 15, 4, 6), 7)
        self.assertEqual(segment_tree.query(1, 1, 15, 7, 11), 14)
        self.assertEqual(segment_tree.query(1, 1, 15, 7, 12), 15)

    def test_update(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        segment_tree = SegmentTree(15)
        segment_tree.build(1, 1, 15, A)
        segment_tree.update(1, 1, 15, 1, 3, 111)
        self.assertEqual(segment_tree.query(1, 1, 15, 1, 15), 111)
        segment_tree.update(1, 1, 15, 7, 8, 235)
        self.assertEqual(segment_tree.query(1, 1, 15, 1, 15), 235)

    def test_query(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        segment_tree = SegmentTree(15)
        segment_tree.build(1, 1, 15, A)
        self.assertEqual(segment_tree.query(1, 1, 15, 4, 6), 7)
        self.assertEqual(segment_tree.query(1, 1, 15, 7, 11), 14)
        self.assertEqual(segment_tree.query(1, 1, 15, 7, 12), 15)


if __name__ == "__main__":
    unittest.main()