import unittest
from merge_two_lists import Node, SortedLinkedList, merge_lists

class TestMergeTwoLists(unittest.TestCase):

    def setUp(self):
        self.test_data_odd = (3, 9, -11, 0, 7, 5, 1, -1)
        self.test_data_even = (4, 6, 2, 0, 8, 10, 3, -2)

    def test_sorted_linked_list(self):
        list_odd = SortedLinkedList(self.test_data_odd)
        self.assertEqual(tuple(list_odd), tuple(sorted(self.test_data_odd)))
        
        list_even = SortedLinkedList(self.test_data_even)
        self.assertEqual(tuple(list_even), tuple(sorted(self.test_data_even)))

    def test_len_of_sorted_linked_list(self):
        list_odd = SortedLinkedList(self.test_data_odd)
        self.assertEqual(len(list_odd), 8)
        
        list_even = SortedLinkedList(range(3))
        self.assertEqual(len(list_even), 3)

    def test_string_representation_of_sorted_linked_list(self):
        list_odd = SortedLinkedList(self.test_data_odd)
        self.assertEqual(str(list_odd), '-11 -> -1 -> 0 -> 1 -> 3 -> 5 -> 7 -> 9')
        
        list_even = SortedLinkedList(self.test_data_even)
        self.assertEqual(str(list_even), '-2 -> 0 -> 2 -> 3 -> 4 -> 6 -> 8 -> 10')

    def test_merge_lists(self):
        list_odd = SortedLinkedList(self.test_data_odd)
        list_even = SortedLinkedList(self.test_data_even)
        merged = merge_lists(list_odd, list_even)
        
        self.assertEqual(len(merged), 16)
        self.assertEqual(str(merged),'-11 -> -2 -> -1 -> 0 -> 0 -> 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10')
        self.assertEqual(list(merged), list(sorted(self.test_data_odd + self.test_data_even)))

if __name__ == '__main__':
    unittest.main()