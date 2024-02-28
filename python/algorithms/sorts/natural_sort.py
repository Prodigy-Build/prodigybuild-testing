import unittest
from natural_sort import natural_sort

class TestNaturalSort(unittest.TestCase):

    def test_natural_sort(self):
        example1 = ['2 ft 7 in', '1 ft 5 in', '10 ft 2 in', '2 ft 11 in', '7 ft 6 in']
        self.assertEqual(natural_sort(example1), ['1 ft 5 in', '2 ft 7 in', '2 ft 11 in', '7 ft 6 in', '10 ft 2 in'])

        example2 = ['Elm11', 'Elm12', 'Elm2', 'elm0', 'elm1', 'elm10', 'elm13', 'elm9']
        self.assertEqual(natural_sort(example2), ['elm0', 'elm1', 'Elm2', 'elm9', 'elm10', 'Elm11', 'Elm12', 'elm13'])

if __name__ == '__main__':
    unittest.main()