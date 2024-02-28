import unittest

class TestLinkedList(unittest.TestCase):

    def setUp(self):
        self.link = LinkedList()

    def test_middle_element_none(self):
        self.assertEqual(self.link.middle_element(), None)
            
    def test_push_and_middle(self):
        self.link.push(5)
        self.link.push(6)
        self.link.push(8)
        self.link.push(8)
        self.link.push(10)
        self.link.push(12)
        self.link.push(17)
        self.link.push(7)
        self.link.push(3)
        self.link.push(20)
        self.link.push(-20)
        self.assertEqual(self.link.middle_element(), 12)

if __name__ == "__main__":
    unittest.main()