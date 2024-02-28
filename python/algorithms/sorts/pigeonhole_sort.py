import unittest
from pigeonhole_sort import pigeonhole_sort

class TestPigeonholeSort(unittest.TestCase):
    
    def test_pigeonhole_sort(self):
        data = [8, 3, 2, 7, 4, 6, 8]
        b = sorted(data.copy())
        pigeonhole_sort(data)
        self.assertEqual(data, b)
        
    def test_pigeonhole_empty(self):
        data = []
        pigeonhole_sort(data)
        self.assertEqual(data, [])

    def test_pigeonhole_one_element(self):
        data = [5]
        pigeonhole_sort(data)
        self.assertEqual(data, [5])

    def test_pigeonhole_sort_negative(self):
        data = [8, -3, 2, -7, 4, -6, 8]
        b = sorted(data.copy())
        pigeonhole_sort(data)
        self.assertEqual(data, b)
        
    def test_pigeonhole_non_integer(self):
        data = [8, 3.4, 2, "7", 4, 6, 8]
        with self.assertRaises(AssertionError):
            pigeonhole_sort(data)

if __name__ == '__main__':
    unittest.main()