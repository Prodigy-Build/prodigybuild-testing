import unittest


class TestChineseRemainderTheorem(unittest.TestCase):
    
    def test_chinese_remainder_theorem(self):
        self.assertEqual(chinese_remainder_theorem(5, 1, 7, 3), 31)
        self.assertEqual(chinese_remainder_theorem(6, 1, 4, 3), 14)
    
    def test_chinese_remainder_theorem2(self):
        self.assertEqual(chinese_remainder_theorem2(5, 1, 7, 3), 31)
        self.assertEqual(chinese_remainder_theorem2(6, 1, 4, 3), 14)
    
    def test_invert_modulo(self):
        self.assertEqual(invert_modulo(2, 5), 3)
        self.assertEqual(invert_modulo(8, 7), 1)
    
    def test_extended_euclid(self):
        self.assertEqual(extended_euclid(10, 6), (-1, 2))
        self.assertEqual(extended_euclid(7, 5), (-2, 3))


if __name__ == '__main__':
    unittest.main()