import unittest

class SdbmTestCase(unittest.TestCase):
    def test_sdbm(self):
        self.assertEqual(sdbm('Algorithms'), 1462174910723540325254304520539387479031000036)
        self.assertEqual(sdbm('scramble bits'), 730247649148944819640658295400555317318720608290373040936089)

if __name__ == '__main__':
    unittest.main()