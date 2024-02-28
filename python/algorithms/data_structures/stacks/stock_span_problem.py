import unittest

class TestStockSpanProblem(unittest.TestCase):

    def test_calculation_span(self):
        price = [10, 4, 5, 90, 120, 80]
        S = [0 for i in range(len(price) + 1)]
        calculation_span(price, S)
        self.assertEqual(S, [1, 1, 2, 4, 5, 1])

    def test_empty_price_list(self):
        price = []
        S = [0 for i in range(len(price) + 1)]
        calculation_span(price, S)
        self.assertEqual(S, [])


if __name__ == '__main__':
    unittest.main()