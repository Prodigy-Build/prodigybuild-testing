import unittest


class TestPigeonSort(unittest.TestCase):

    def test_pigeon_sort(self):
        self.assertEqual(pigeon_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(pigeon_sort([]), [])
        self.assertEqual(pigeon_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(pigeon_sort([1]), [1])
        self.assertEqual(pigeon_sort([25, 20, 18, 8, 6, 3, 1]), [1, 3, 6, 8, 18, 20, 25])


if __name__ == "__main__":
    unittest.main()