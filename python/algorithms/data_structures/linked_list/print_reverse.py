import unittest
from io import StringIO
import sys

class TestLinkedList(unittest.TestCase):

    def setUp(self):
        self.linked_list = make_linked_list([14, 52, 14, 12, 43])

    def test_make_linked_list(self):
        self.assertEqual(str(self.linked_list), '14->52->14->12->43')
        self.assertRaises(Exception, make_linked_list, [])

    def test_print_reverse(self):
        captured_output = StringIO()
        sys.stdout = captured_output

        print_reverse(self.linked_list)
        sys.stdout = sys.__stdout__

        self.assertEqual(captured_output.getvalue(), '43\n12\n14\n52\n14\n')

if __name__ == '__main__':
    unittest.main()