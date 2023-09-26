import unittest


class TestAllCombinations(unittest.TestCase):
    def test_generate_all_combinations(self):
        self.assertEqual(generate_all_combinations(n=4, k=2), [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]])


if __name__ == '__main__':
    unittest.main()