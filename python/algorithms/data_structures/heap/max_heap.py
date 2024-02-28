class TestBinaryHeap(unittest.TestCase):
    def setUp(self):
        self.binary_heap = BinaryHeap()

    def test_insert(self):
        self.binary_heap.insert(6)
        self.assertEqual(self.binary_heap.get_list, [6])
        self.assertEqual(len(self.binary_heap), 1)

        self.binary_heap.insert(10)
        self.assertEqual(self.binary_heap.get_list, [10, 6])
        self.assertEqual(len(self.binary_heap), 2)

        self.binary_heap.insert(15)
        self.assertEqual(self.binary_heap.get_list, [15, 6, 10])
        self.assertEqual(len(self.binary_heap), 3)

        self.binary_heap.insert(12)
        self.assertEqual(self.binary_heap.get_list, [15, 12, 10, 6])
        self.assertEqual(len(self.binary_heap), 4)

    def test_pop(self):
        self.binary_heap.insert(6)
        self.binary_heap.insert(10)
        self.binary_heap.insert(15)
        self.binary_heap.insert(12)

        self.assertEqual(self.binary_heap.pop(), 15)
        self.assertEqual(self.binary_heap.get_list, [12, 6, 10])
        self.assertEqual(len(self.binary_heap), 3)

        self.assertEqual(self.binary_heap.pop(), 12)
        self.assertEqual(self.binary_heap.get_list, [10, 6])
        self.assertEqual(len(self.binary_heap), 2)

    def test_get_list(self):
        self.binary_heap.insert(6)
        self.binary_heap.insert(10)
        self.binary_heap.insert(15)
        self.binary_heap.insert(12)

        self.assertEqual(self.binary_heap.get_list, [15, 12, 10, 6])

    def test_len(self):
        self.binary_heap.insert(6)
        self.binary_heap.insert(10)
        self.binary_heap.insert(15)
        self.binary_heap.insert(12)

        self.assertEqual(len(self.binary_heap), 4)


if __name__ == "__main__":
    unittest.main()