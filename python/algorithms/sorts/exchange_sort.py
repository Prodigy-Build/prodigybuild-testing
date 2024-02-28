import unittest

class TestExchangeSort(unittest.TestCase):
    
    def test_exchange_sort(self):
        self.assertEqual(exchange_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
        self.assertEqual(exchange_sort([-1, -2, -3]), [-3, -2, -1])
        self.assertEqual(exchange_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])
        self.assertEqual(exchange_sort([0, 10, -2, 5, 3]), [-2, 0, 3, 5, 10])
        self.assertEqual(exchange_sort([]), [])

if __name__ == "__main__":
    unittest.main()