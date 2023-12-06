import unittest

class TestGenerateAllCombinations(unittest.TestCase):

    def setUp(self):
        self.combinations_4_2 = [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]

    def test_generate_all_combinations(self):
        self.assertEqual(generate_all_combinations(4, 2), self.combinations_4_2)

if __name__ == '__main__':
    unittest.main()