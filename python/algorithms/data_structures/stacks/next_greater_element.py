import unittest

class TestNGE(unittest.TestCase):

    def setUp(self):
        self.arr1 = [-10, -5, 0, 5, 5.1, 11, 13, 21, 3, 4, -21, -10, -5, -1, 0]
        self.expect1 = [-5, 0, 5, 5.1, 11, 13, 21, -1, 4, -1, -10, -5, -1, 0, -1]
        self.arr2 = [1, 3, 2, 4]
        self.expect2 = [3, 4, 4, -1]
        
    def test_next_greatest_element_slow(self):
        self.assertEqual(self.expect1, next_greatest_element_slow(self.arr1))
        self.assertEqual(self.expect2, next_greatest_element_slow(self.arr2))

    def test_next_greatest_element_fast(self):
        self.assertEqual(self.expect1, next_greatest_element_fast(self.arr1))
        self.assertEqual(self.expect2, next_greatest_element_fast(self.arr2))

    def test_next_greatest_element(self):
        self.assertEqual(self.expect1, next_greatest_element(self.arr1))
        self.assertEqual(self.expect2, next_greatest_element(self.arr2))

if __name__ == "__main__":
    unittest.main()