import unittest

class TestQuickSort(unittest.TestCase):

    def test_in_place_quick_sort(self):
        a = np.array([3, 2, 1])
        count = _in_place_quick_sort(a, 0, 2)
        self.assertEqual(list(a), [1, 2, 3])
        self.assertEqual(count, 3)

    def test_in_place_partition(self):
        a = np.array([3, 2, 1])
        p, count = _in_place_partition(a, 0, 2)
        self.assertEqual(list(a), [1, 2, 3])
        self.assertEqual(count, 3)

    def test_in_place_quick_sort_inverted(self):
        a = np.array([1, 2, 3])
        count = _in_place_quick_sort(a, 0, 2)
        self.assertEqual(list(a), [1, 2, 3])
        self.assertEqual(count, 3)

    def test_in_place_partition_inverted(self):
        a = np.array([1, 2, 3])
        p, count = _in_place_partition(a, 0, 2)
        self.assertEqual(list(a), [1, 2, 3])
        self.assertEqual(count, 3)

if __name__ == '__main__':
     unittest.main()