import unittest

class TestHammingCode(unittest.TestCase):
    def test_emitter_converter(self):
        self.assertEqual(emitter_converter(4, "101010111111"), ['1', '1', '1', '1', '0', '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1'])
    
    def test_receptor_converter(self):
        self.assertEqual(receptor_converter(4, "1111010010111111"), (['1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1'], True))

if __name__ == '__main__':
    unittest.main()