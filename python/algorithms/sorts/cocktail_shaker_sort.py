import unittest

class TestCocktailShakerSort(unittest.TestCase):
    
    def test_sorted_list(self):
        self.assertEqual(
            cocktail_shaker_sort([1, 2, 3, 4, 5]),
            [1, 2, 3, 4, 5]
        )

    def test_reversed(self):
        self.assertEqual(
            cocktail_shaker_sort([5, 4, 3, 2, 1]),
            [1, 2, 3, 4, 5]
        )

    def test_unsorted(self):
        self.assertEqual(
            cocktail_shaker_sort([4, 5, 2, 1, 2]),
            [1, 2, 2, 4, 5]
        )

    def test_with_negative(self):
        self.assertEqual(
            cocktail_shaker_sort([-4, 5, 0, 1, 2, 11]),
            [-4, 0, 1, 2, 5, 11]
        )

    def test_with_floats(self):
        self.assertEqual(
            cocktail_shaker_sort([0.1, -2.4, 4.4, 2.2]),
            [-2.4, 0.1, 2.2, 4.4]
        )

if __name__ == '__main__':
    unittest.main()