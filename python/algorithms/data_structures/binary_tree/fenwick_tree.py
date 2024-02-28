import unittest

class TestFenwickTree(unittest.TestCase):
    
    def setUp(self):
        self.arr = [i for i in range(10)]  # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        self.ft = FenwickTree(self.arr)

    def test_initialisation(self):
        self.assertEqual(self.ft.get_array(), self.arr)

    def test_add(self):
        self.ft.add(5, 10)  # Add 10 to the 5th index.
        self.assertEqual(self.ft.get(5), 15)

    def test_update(self):
        self.ft.update(5, 10)  # Update the 5th index with 10.
        self.assertEqual(self.ft.get(5), 10)

    def test_prefix_query(self):
        self.assertEqual(self.ft.query(0, 5), sum(self.arr[:5]))

    def test_range_query(self):
        self.assertEqual(self.ft.query(5, 10), sum(self.arr[5:10]))

    def test_rank_query(self):
        self.assertEqual(self.ft.rank_query(15), 5)

if __name__ == '__main__':
    unittest.main()
