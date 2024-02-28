import unittest

class TestSlowSort(unittest.TestCase):
    def test_sorts_sequence_in_place(self):
        seq = [1, 6, 2, 5, 3, 4, 4, 5]
        slowsort(seq)
        self.assertEqual(seq, [1, 2, 3, 4, 4, 5, 5, 6])

    def test_handles_empty_sequence(self):
        seq = []
        slowsort(seq)
        self.assertEqual(seq, [])

    def test_handles_single_element_sequence(self):
        seq = [2]
        slowsort(seq)
        self.assertEqual(seq, [2])

    def test_handles_sorted_sequence(self):
        seq = [1, 2, 3, 4]
        slowsort(seq)
        self.assertEqual(seq, [1, 2, 3, 4])

    def test_handles_reverse_sorted_sequence(self):
        seq = [4, 3, 2, 1]
        slowsort(seq)
        self.assertEqual(seq, [1, 2, 3, 4])

    def test_sorts_partial_sequence(self):
        seq = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
        slowsort(seq, 2, 7)
        self.assertEqual(seq, [9, 8, 2, 3, 4, 5, 6, 7, 1, 0])

    def test_sorts_sequence_to_position(self):
        seq = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
        slowsort(seq, end=4)
        self.assertEqual(seq, [5, 6, 7, 8, 9, 4, 3, 2, 1, 0])

    def test_sorts_sequence_from_position(self):
        seq = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
        slowsort(seq, start=5)
        self.assertEqual(seq, [9, 8, 7, 6, 5, 0, 1, 2, 3, 4])

if __name__ == "__main__":
    unittest.main()