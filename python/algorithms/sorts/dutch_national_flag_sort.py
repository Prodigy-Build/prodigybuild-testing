import unittest
from dutch_national_flag_sort import dutch_national_flag_sort

class TestDutchNationalFlagSort(unittest.TestCase):

    def test_empty(self):
        self.assertEqual(dutch_national_flag_sort([]), [])

    def test_single_element(self):
        self.assertEqual(dutch_national_flag_sort([0]), [0])

    def test_multiple_elements(self):
        self.assertEqual(dutch_national_flag_sort([2, 1, 0, 0, 1, 2]), [0, 0, 1, 1, 2, 2])
        self.assertEqual(dutch_national_flag_sort([0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]), [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2])

    def test_invalid_input(self):
        self.assertRaises(ValueError, dutch_national_flag_sort, "abacab")
        self.assertRaises(ValueError, dutch_national_flag_sort, "Abacab")
        self.assertRaises(ValueError, dutch_national_flag_sort, [3, 2, 3, 1, 3, 0, 3])
        self.assertRaises(ValueError, dutch_national_flag_sort, [-1, 2, -1, 1, -1, 0, -1])
        self.assertRaises(ValueError, dutch_national_flag_sort, [1.1, 2, 1.1, 1, 1.1, 0, 1.1])

if __name__ == '__main__':
    unittest.main()