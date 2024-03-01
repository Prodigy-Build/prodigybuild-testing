import unittest

class TestDjb2(unittest.TestCase):
    def test_djb2(self):
        self.assertEqual(djb2('Algorithms'), 3782405311)
        self.assertEqual(djb2('scramble bits'), 1609059040)

if __name__ == '__main__':
    unittest.main()