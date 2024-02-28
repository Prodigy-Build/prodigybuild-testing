import unittest

class TestMergerSort(unittest.TestCase):
    
    def test_merge_sort(self):
        result = merge_sort([0, 5, 3, 2, 2])
        self.assertEqual(result, [0, 2, 2, 3, 5])

    def test_merge_sort_empty_list(self):
        result = merge_sort([])
        self.assertEqual(result, [])

    def test_merge_sort_negative_numbers(self):
        result = merge_sort([-2, -5, -45])
        self.assertEqual(result, [-45, -5, -2])

    def test_merge_sort_mixed_datas(self):
        result = merge_sort([3.14, -2, -5, 11, 'a', 'zzz', 'foo'])
        self.assertEqual(result, ['a', 'foo', 'zzz', -5, -2, 3.14, 11])

if __name__ == '__main__':
    unittest.main()