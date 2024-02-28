import unittest

class TestLinkedList(unittest.TestCase):

    def setUp(self):
        self.ll = LinkedList()
        for i in range(1, 6):
            self.ll.push(i)

    def test_print_list(self):
        self.assertEqual(self.ll.print_list(), [5, 4, 3, 2, 1])

    def test_push(self):
        self.ll.push(0)
        self.assertEqual(self.ll.print_list(), [0, 5, 4, 3, 2, 1])

    def test_swap_nodes(self):
        self.ll.swap_nodes(1, 5)
        self.assertEqual(self.ll.print_list(), [1, 4, 3, 2, 5])

    def test_swap_same_node(self):
        self.ll.swap_nodes(3, 3)
        self.assertEqual(self.ll.print_list(), [5, 4, 3, 2, 1])

    def test_swap_nodes_not_in_list(self):
        self.ll.swap_nodes(6, 7)
        self.assertEqual(self.ll.print_list(), [5, 4, 3, 2, 1])


if __name__ == "__main__":
    unittest.main()