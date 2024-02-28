import unittest


class TestLinkedList(unittest.TestCase):
    def setUp(self):
        self.list_data = [1, 3, 5, 32, 44, 12, 43]
        self.expected_result = "<1> ---> <3> ---> <5> ---> <32> ---> <44> ---> <12> ---> <43> ---> <END>"

    def test_make_linked_list(self):
        linked_list = make_linked_list(self.list_data)
        self.assertEqual(str(linked_list), self.expected_result)

    def test_empty_elements_list(self):
        with self.assertRaises(Exception):
            make_linked_list([])


if __name__ == '__main__':
    unittest.main()