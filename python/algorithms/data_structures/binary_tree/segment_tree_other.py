```python
import operator
import unittest
from queue import Queue
from typing import List, Tuple, Union


class SegmentTreeNode:
    def __init__(self, start: int, end: int, val: Union[int, float], left=None, right=None):
        self.start = start
        self.end = end
        self.val = val
        self.mid = (start + end) // 2
        self.left = left
        self.right = right

    def __repr__(self):
        return f"SegmentTreeNode(start={self.start}, end={self.end}, val={self.val})"


class SegmentTree:
    def __init__(self, collection: List[Union[int, float]], function):
        self.collection = collection
        self.fn = function
        if self.collection:
            self.root = self._build_tree(0, len(collection) - 1)

    def update(self, i: int, val: Union[int, float]) -> None:
        self._update_tree(self.root, i, val)

    def query_range(self, i: int, j: int) -> Union[int, float]:
        return self._query_range(self.root, i, j)

    def _build_tree(self, start: int, end: int) -> SegmentTreeNode:
        if start == end:
            return SegmentTreeNode(start, end, self.collection[start])
        mid = (start + end) // 2
        left = self._build_tree(start, mid)
        right = self._build_tree(mid + 1, end)
        return SegmentTreeNode(start, end, self.fn(left.val, right.val), left, right)

    def _update_tree(self, node: SegmentTreeNode, i: int, val: Union[int, float]) -> None:
        if node.start == i and node.end == i:
            node.val = val
            return
        if i <= node.mid:
            self._update_tree(node.left, i, val)
        else:
            self._update_tree(node.right, i, val)
        node.val = self.fn(node.left.val, node.right.val)

    def _query_range(self, node: SegmentTreeNode, i: int, j: int) -> Union[int, float]:
        if node.start == i and node.end == j:
            return node.val

        if i <= node.mid:
            if j <= node.mid:
                return self._query_range(node.left, i, j)
            else:
                return self.fn(
                    self._query_range(node.left, i, node.mid),
                    self._query_range(node.right, node.mid + 1, j),
                )
        else:
            return self._query_range(node.right, i, j)

    def traverse(self) -> Tuple[SegmentTreeNode]:
        if self.root is not None:
            queue = Queue()
            queue.put(self.root)
            while not queue.empty():
                node = queue.get()
                yield node

                if node.left is not None:
                    queue.put(node.left)

                if node.right is not None:
                    queue.put(node.right)


class TestSegmentTree(unittest.TestCase):
    def test_add(self):
        num_arr = SegmentTree([2, 1, 5, 3, 4], operator.add)
        self.assertEqual(tuple(num_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=15),
            SegmentTreeNode(start=0, end=2, val=8),
            SegmentTreeNode(start=3, end=4, val=7),
            SegmentTreeNode(start=0, end=1, val=3),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=1)
        ))

        num_arr.update(1, 5)
        self.assertEqual(tuple(num_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=19),
            SegmentTreeNode(start=0, end=2, val=12),
            SegmentTreeNode(start=3, end=4, val=7),
            SegmentTreeNode(start=0, end=1, val=7),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=5)
        ))

        self.assertEqual(num_arr.query_range(3, 4), 7)
        self.assertEqual(num_arr.query_range(2, 2), 5)
        self.assertEqual(num_arr.query_range(1, 3), 13)

    def test_max(self):
        max_arr = SegmentTree([2, 1, 5, 3, 4], max)
        self.assertEqual(tuple(max_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=5),
            SegmentTreeNode(start=0, end=2, val=5),
            SegmentTreeNode(start=3, end=4, val=4),
            SegmentTreeNode(start=0, end=1, val=2),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=1)
        ))

        max_arr.update(1, 5)
        self.assertEqual(tuple(max_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=5),
            SegmentTreeNode(start=0, end=2, val=5),
            SegmentTreeNode(start=3, end=4, val=4),
            SegmentTreeNode(start=0, end=1, val=5),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=5)
        ))

        self.assertEqual(max_arr.query_range(3, 4), 4)
        self.assertEqual(max_arr.query_range(2, 2), 5)
        self.assertEqual(max_arr.query_range(1, 3), 5)

    def test_min(self):
        min_arr = SegmentTree([2, 1, 5, 3, 4], min)
        self.assertEqual(tuple(min_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=1),
            SegmentTreeNode(start=0, end=2, val=1),
            SegmentTreeNode(start=3, end=4, val=3),
            SegmentTreeNode(start=0, end=1, val=1),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=1)
        ))

        min_arr.update(1, 5)
        self.assertEqual(tuple(min_arr.traverse()), (
            SegmentTreeNode(start=0, end=4, val=2),
            SegmentTreeNode(start=0, end=2, val=2),
            SegmentTreeNode(start=3, end=4, val=3),
            SegmentTreeNode(start=0, end=1, val=2),
            SegmentTreeNode(start=2, end=2, val=5),
            SegmentTreeNode(start=3, end=3, val=3),
            SegmentTreeNode(start=4, end=4, val=4),
            SegmentTreeNode(start=0, end=0, val=2),
            SegmentTreeNode(start=1, end=1, val=5)
        ))

        self.assertEqual(min_arr.query_range(3, 4), 3)
        self.assertEqual(min_arr.query_range(2, 2), 5)
        self.assertEqual(min_arr.query_range(1, 3), 3)


if __name__ == "__main__":
    unittest.main()
```