import unittest
from functools import reduce

class TestSegmentTree(unittest.TestCase):
    def setUp(self):
        self.test_array = [1, 10, -2, 9, -3, 8, 4, -7, 5, 6, 11, -12]
        self.test_updates = {
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
        self.min_segment_tree = SegmentTree(self.test_array, min)
        self.max_segment_tree = SegmentTree(self.test_array, max)
        self.sum_segment_tree = SegmentTree(self.test_array, lambda a, b: a + b)

    def test_all_segments(self):
        for i in range(len(self.test_array)):
            for j in range(i, len(self.test_array)):
                min_range = reduce(min, self.test_array[i : j + 1])
                max_range = reduce(max, self.test_array[i : j + 1])
                sum_range = reduce(lambda a, b: a + b, self.test_array[i : j + 1])
                self.assertEqual(min_range, self.min_segment_tree.query(i, j))
                self.assertEqual(max_range, self.max_segment_tree.query(i, j))
                self.assertEqual(sum_range, self.sum_segment_tree.query(i, j))

    def test_updates(self):
        for index, value in self.test_updates.items():
            self.test_array[index] = value
            self.min_segment_tree.update(index, value)
            self.max_segment_tree.update(index, value)
            self.sum_segment_tree.update(index, value)
            self.test_all_segments()

if __name__ == "__main__":
    unittest.main()