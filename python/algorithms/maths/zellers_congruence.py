import unittest
from datetime import datetime
from zellers_congruence import zeller

class TestZeller(unittest.TestCase):
    def test_zeller(self):
        self.assertEqual(zeller('01-31-2010'), 'Your date 01-31-2010, is a Sunday!')
        self.assertRaises(ValueError, zeller, '13-31-2010')
        self.assertRaises(ValueError, zeller, '.2-31-2010')
        self.assertRaises(ValueError, zeller, '01-33-2010')
        self.assertRaises(ValueError, zeller, '01-.4-2010')
        self.assertRaises(ValueError, zeller, '01-31*2010')
        self.assertRaises(ValueError, zeller, '01^31-2010')
        self.assertRaises(ValueError, zeller, '01-31-8999')
        self.assertRaises(TypeError, zeller)
        self.assertRaises(ValueError, zeller, '')
        self.assertRaises(ValueError, zeller, '01-31-19082939')

if __name__ == '__main__':
    unittest.main()