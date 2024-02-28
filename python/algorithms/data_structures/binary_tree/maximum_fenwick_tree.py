import unittest

class TestMaxFenwickTree(unittest.TestCase):
    
    def test_update_and_query(self):
        ft = MaxFenwickTree(5)
        self.assertEqual(ft.query(0, 5), 0)
        ft.update(4, 100)
        self.assertEqual(ft.query(0, 5), 100)
        ft.update(4, 0)
        ft.update(2, 20)
        self.assertEqual(ft.query(0, 5), 20)
        ft.update(4, 10)
        self.assertEqual(ft.query(2, 5), 20)
        self.assertEqual(ft.query(1, 5), 20)
        ft.update(2, 0)
        self.assertEqual(ft.query(0, 5), 10)

    def test_large_size(self):
        ft = MaxFenwickTree(10000)
        ft.update(255, 30)
        self.assertEqual(ft.query(0, 10000), 30)

    def test_query_single_index(self):
        ft = MaxFenwickTree(6)
        ft.update(5, 1)
        self.assertEqual(ft.query(5, 6), 1)
        
        ft = MaxFenwickTree(6)
        ft.update(0, 1000)
        self.assertEqual(ft.query(0, 1), 1000)


if __name__ == "__main__":
    unittest.main()