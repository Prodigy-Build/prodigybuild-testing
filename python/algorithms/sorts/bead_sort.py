import unittest

class TestBeadSort(unittest.TestCase):
    def test_bead_sort(self):
        self.assertEqual(bead_sort([6, 11, 12, 4, 1, 5]), [1, 4, 5, 6, 11, 12])
        self.assertEqual(bead_sort([9, 8, 7, 6, 5, 4 ,3, 2, 1]), [1, 2, 3, 4, 5, 6, 7, 8, 9])
        self.assertEqual(bead_sort([5, 0, 4, 3]), [0, 3, 4, 5])
        self.assertEqual(bead_sort([8, 2, 1]), [1, 2, 8])

    def test_bead_sort_negative_cases(self):
        with self.assertRaises(TypeError):
            bead_sort([1, .9, 0.0, 0, -1, -.9])
        
        with self.assertRaises(TypeError):
            bead_sort("Hello world")

unittest.main()