import unittest
from gnome_sort import gnome_sort

class TestGnomeSort(unittest.TestCase):

    def test_gnome_sort(self):
        self.assertEqual(gnome_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(gnome_sort([]), [])
        self.assertEqual(gnome_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(gnome_sort(list(set("Gnomes are stupid!"))), [' ', '!', 'G', 'a', 'd', 'e', 'i', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u'])

if __name__ == '__main__':
    unittest.main()