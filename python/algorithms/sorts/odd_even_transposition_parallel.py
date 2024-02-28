import unittest

class TestOddEvenTransposition(unittest.TestCase):
    def test_odd_even_transposition(self):
        test_array = list(range(10, 0, -1))
        self.assertEqual(odd_even_transposition(test_array), sorted(test_array))

        test_array = [11, 55, 9, 43, 77]
        self.assertEqual(odd_even_transposition(test_array), sorted(test_array))

        test_array = [5]
        self.assertEqual(odd_even_transposition(test_array), sorted(test_array))


if __name__ == '__main__':
    unittest.main()