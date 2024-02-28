import unittest

class TestRadixSort(unittest.TestCase):

    def test_msd_radix_sort(self):
        self.assertEqual(msd_radix_sort([40, 12, 1, 100, 4]), [1, 4, 12, 40, 100])
        self.assertEqual(msd_radix_sort([]), [])
        with self.assertRaises(ValueError):
            msd_radix_sort([-1, 34, 45])

    def test_msd_radix_sort_inplace(self):
        lst = [1, 345, 23, 89, 0, 3]
        msd_radix_sort_inplace(lst)
        self.assertEqual(lst, sorted(lst))

        lst = [1, 43, 0, 0, 0, 24, 3, 3]
        msd_radix_sort_inplace(lst)
        self.assertEqual(lst, sorted(lst))

        lst = []
        msd_radix_sort_inplace(lst)
        self.assertEqual(lst, [])

        lst = [-1, 34, 23, 4, -42]
        self.assertRaises(ValueError, msd_radix_sort_inplace, lst)

if __name__ == "__main__":
    unittest.main()