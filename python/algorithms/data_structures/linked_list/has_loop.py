import unittest

class TestNodeHasLoop(unittest.TestCase):

    def test_has_loop(self):
        root_node = Node(1)
        root_node.next_node = Node(2)
        root_node.next_node.next_node = Node(3)
        root_node.next_node.next_node.next_node = Node(4)
        self.assertEqual(root_node.has_loop,False)

    def test_has_loop_with_loop(self):
        root_node = Node(1)
        root_node.next_node = Node(2)
        root_node.next_node.next_node = Node(3)
        root_node.next_node.next_node.next_node = root_node.next_node
        self.assertEqual(root_node.has_loop,True)

    def test_has_loop_with_same_data(self):
        root_node = Node(5)
        root_node.next_node = Node(6)
        root_node.next_node.next_node = Node(5)
        root_node.next_node.next_node.next_node = Node(6)
        self.assertEqual(root_node.has_loop,False)

    def test_has_loop_with_single_node(self):
        root_node = Node(1)
        self.assertEqual(root_node.has_loop,False)


if __name__ == "__main__":
    unittest.main()