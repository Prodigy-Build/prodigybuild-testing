import unittest

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None

class TestPalindromeLinkedList(unittest.TestCase):
    def setUp(self):
        self.node1 = Node(1)
        self.node2 = Node(2)
        self.node3 = Node(2)
        self.node4 = Node(1)
        self.node1.next = self.node2
        self.node2.next = self.node3
        self.node3.next = self.node4

    def test_is_palindrome(self):
        self.assertEqual(is_palindrome(self.node1), True)

    def test_is_palindrome_stack(self):
        self.assertEqual(is_palindrome_stack(self.node1), True)

    def test_is_palindrome_dict(self):
        self.assertEqual(is_palindrome_dict(self.node1), True)

    def tearDown(self):
        self.node1 = None
        self.node2 = None
        self.node3 = None
        self.node4 = None
          
if __name__ == '__main__':
    unittest.main()