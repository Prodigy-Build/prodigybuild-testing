import unittest


class TestOddEvenTransposition(unittest.TestCase):

    def test_odd_even_transposition(self):
        self.assertEqual(odd_even_transposition([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
        self.assertEqual(odd_even_transposition([13, 11, 18, 0, -1]), [-1, 0, 11, 13, 18])
        self.assertEqual(odd_even_transposition([-.1, 1.1, .1, -2.9]), [-2.9, -0.1, 0.1, 1.1])

    def test_odd_even_transposition_with_duplicates(self):
        self.assertEqual(odd_even_transposition([3, 1, 2, 1, 2, 3, 3, 1, 2]), [1, 1, 1, 2, 2, 2, 3, 3, 3])

    def test_odd_even_transposition_with_single_element(self):
        self.assertEqual(odd_even_transposition([123]), [123])
        
    def test_odd_even_transposition_with_empty_list(self):
        self.assertEqual(odd_even_transposition([]), [])


if __name__ == '__main__':
    unittest.main()