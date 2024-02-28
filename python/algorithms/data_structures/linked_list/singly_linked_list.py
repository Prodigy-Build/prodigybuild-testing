import unittest

class TestSinglyLinkedList(unittest.TestCase):
    def test_insertion_and_deletion(self):
        linked_list = LinkedList()
        self.assertEqual(linked_list.is_empty(), True)
        self.assertEqual(str(linked_list), "")
        with self.assertRaises(IndexError):
            linked_list.delete_head() 
        with self.assertRaises(IndexError):  
            linked_list.delete_tail()
        for i in range(10):
            linked_list.insert_tail(i)
            self.assertEqual(len(linked_list), i+1)
        self.assertEqual(str(linked_list), "->".join(str(i) for i in range(0, 10)))
        linked_list.insert_head(-1)
        linked_list.insert_tail(10)
        self.assertEqual(str(linked_list), "->".join(str(i) for i in range(-1, 11)))
        self.assertEqual(linked_list.delete_head(), -1)
        self.assertEqual(linked_list.delete_tail(), 10)
        self.assertEqual(len(linked_list), 9)
        self.assertEqual(str(linked_list), "->".join(str(i) for i in range(0, 9)))
        for i in range(0, 9):
            linked_list[i] = -i
        self.assertTrue(all(linked_list[i] == -i for i in range(0, 9)))
        linked_list.reverse()
        self.assertEqual(str(linked_list), "->".join(str(i) for i in range(-8, 1)))
        
    def test_varying_data_types(self):
        test_input = ["Hello, world!", 7, 5555, 0, -192.55555, 77.9, 10, None]
        linked_list = LinkedList()
        for i in test_input:
            linked_list.insert_tail(i)
        self.assertEqual(linked_list.is_empty(), False)
        self.assertEqual(str(linked_list), 
                         "->".join(map(str, test_input)))
        self.assertEqual(linked_list.delete_head(), "Hello, world!")
        self.assertEqual(linked_list.delete_tail(), None)
        linked_list.insert_head(7.77)
        linked_list.insert_tail(77.7)
        self.assertEqual(str(linked_list), 
                         "->".join(map(str, [7.77]+test_input[1:]+[77.7])))
        linked_list.reverse()
        self.assertEqual(str(linked_list), 
                         "->".join(map(str, [77.7]+test_input[1:][::-1]+[7.77])))

if __name__ == "__main__":
    unittest.main()