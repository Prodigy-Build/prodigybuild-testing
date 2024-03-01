```python
import unittest
from functools import reduce
from typing import Any, Callable, Generic, List, TypeVar

T = TypeVar("T")


class SegmentTree(Generic[T]):
    def __init__(self, arr: List[T], fnc: Callable[[T, T], T]) -> None:
        any_type: Any | T = None

        self.N: int = len(arr)
        self.st: List[T] = [any_type for _ in range(self.N)] + arr
        self.fn = fnc
        self.build()

    def build(self) -> None:
        for p in range(self.N - 1, 0, -1):
            self.st[p] = self.fn(self.st[p * 2], self.st[p * 2 + 1])

    def update(self, p: int, v: T) -> None:
        p += self.N
        self.st[p] = v
        while p > 1:
            p = p // 2
            self.st[p] = self.fn(self.st[p * 2], self.st[p * 2 + 1])

    def query(self, l: int, r: int) -> T | None:
        l, r = l + self.N, r + self.N

        res: T | None = None
        while l <= r:
            if l % 2 == 1:
                res = self.st[l] if res is None else self.fn(res, self.st[l])
            if r % 2 == 0:
                res = self.st[r] if res is None else self.fn(res, self.st[r])
            l, r = (l + 1) // 2, (r - 1) // 2
        return res


class TestSegmentTree(unittest.TestCase):
    def test_query(self):
        st = SegmentTree([1, 2, 3], lambda a, b: a + b)
        self.assertEqual(st.query(0, 2), 6)

        st = SegmentTree([3, 1, 2], min)
        self.assertEqual(st.query(0, 2), 1)

        st = SegmentTree([2, 3, 1], max)
        self.assertEqual(st.query(0, 2), 3)

        st = SegmentTree([1, 5, 7, -1, 6], lambda a, b: a + b)
        self.assertEqual(st.query(1, 2), 2)
        self.assertEqual(st.query(1, 1), -1)
        self.assertEqual(st.query(3, 4), 0)

        st = SegmentTree([[1, 2, 3], [3, 2, 1], [1, 1, 1]], lambda a, b: [a[i] + b[i] for i in range(len(a))])
        self.assertEqual(st.query(0, 1), [4, 4, 4])
        self.assertEqual(st.query(1, 2), [4, 3, 2])

    def test_update(self):
        st = SegmentTree([3, 1, 2, 4], min)
        self.assertEqual(st.query(0, 3), 1)
        st.update(2, -1)
        self.assertEqual(st.query(0, 3), -1)

    def test_all_segments(self):
        test_array = [1, 10, -2, 9, -3, 8, 4, -7, 5, 6, 11, -12]
        min_segment_tree = SegmentTree(test_array, min)
        max_segment_tree = SegmentTree(test_array, max)
        sum_segment_tree = SegmentTree(test_array, lambda a, b: a + b)

        for i in range(len(test_array)):
            for j in range(i, len(test_array)):
                min_range = reduce(min, test_array[i: j + 1])
                max_range = reduce(max, test_array[i: j + 1])
                sum_range = reduce(lambda a, b: a + b, test_array[i: j + 1])
                self.assertEqual(min_range, min_segment_tree.query(i, j))
                self.assertEqual(max_range, max_segment_tree.query(i, j))
                self.assertEqual(sum_range, sum_segment_tree.query(i, j))

    def test_updates(self):
        test_array = [1, 10, -2, 9, -3, 8, 4, -7, 5, 6, 11, -12]
        min_segment_tree = SegmentTree(test_array, min)
        max_segment_tree = SegmentTree(test_array, max)
        sum_segment_tree = SegmentTree(test_array, lambda a, b: a + b)

        test_updates = {
            0: 7,
            1: 2,
            2: 6,
            3: -14,
            4: 5,
            5: 4,
            6: 7,
            7: -10,
            8: 9,
            9: 10,
            10: 12,
            11: 1,
        }

        for index, value in test_updates.items():
            test_array[index] = value
            min_segment_tree.update(index, value)
            max_segment_tree.update(index, value)
            sum_segment_tree.update(index, value)

            for i in range(len(test_array)):
                for j in range(i, len(test_array)):
                    min_range = reduce(min, test_array[i: j + 1])
                    max_range = reduce(max, test_array[i: j + 1])
                    sum_range = reduce(lambda a, b: a + b, test_array[i: j + 1])
                    self.assertEqual(min_range, min_segment_tree.query(i, j))
                    self.assertEqual(max_range, max_segment_tree.query(i, j))
                    self.assertEqual(sum_range, sum_segment_tree.query(i, j))


if __name__ == "__main__":
    unittest.main()
```