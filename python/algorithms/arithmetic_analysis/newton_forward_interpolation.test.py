import unittest

class TestNewtonForwardInterpolation(unittest.TestCase):

    def test_ucal(self):
        self.assertEqual(ucal(1, 2), 0)
        self.assertEqual(ucal(1.1, 2), 0.11000000000000011)
        self.assertEqual(ucal(1.2, 2), 0.23999999999999994)

if __name__ == '__main__':
    unittest.main()