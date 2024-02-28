import unittest
from hash_map import HashMap

class TestHashMap(unittest.TestCase):
    def setUp(self):
        self.hm = HashMap()

    def test_set_item(self):
        self.hm['key1'] = 'value1'
        self.assertEqual(self.hm['key1'], 'value1')

    def test_del_item(self):
        self.hm['key1'] = 'value1'
        del self.hm['key1']
        with self.assertRaises(KeyError):
            _ = self.hm['key1']

    def test_get_item(self):
        self.hm['key1'] = 'value1'
        self.assertEqual(self.hm['key1'], 'value1')
    
    def test_len(self):
        self.hm['key1'] = 'value1'
        self.hm['key2'] = 'value2'
        self.assertEqual(len(self.hm), 2)

    def test_resize(self):
        for i in range(10):
            self.hm[str(i)] = i
        self.assertEqual(len(self.hm), 10)
        self.assertEqual(self.hm['5'], 5)

    def test_key_error(self):
        with self.assertRaises(KeyError):
            _ = self.hm['key1']

if __name__ == "__main__":
    unittest.main()