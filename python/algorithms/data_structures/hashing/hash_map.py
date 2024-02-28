```python
import unittest
from algorithms.data_structures.hashing.hash_map import HashMap

class TestHashMap(unittest.TestCase):
    def test_setitem(self):
        hashmap = HashMap()
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        self.assertEqual(hashmap["key1"], "value1")
        self.assertEqual(hashmap["key2"], "value2")

    def test_delitem(self):
        hashmap = HashMap()
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        del hashmap["key1"]
        self.assertNotIn("key1", hashmap)
        self.assertEqual(len(hashmap), 1)

    def test_getitem(self):
        hashmap = HashMap()
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        self.assertEqual(hashmap["key1"], "value1")
        self.assertEqual(hashmap["key2"], "value2")
        with self.assertRaises(KeyError):
            hashmap["key3"]

    def test_len(self):
        hashmap = HashMap()
        self.assertEqual(len(hashmap), 0)
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        self.assertEqual(len(hashmap), 2)
        del hashmap["key1"]
        self.assertEqual(len(hashmap), 1)

    def test_iter(self):
        hashmap = HashMap()
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        keys = set()
        for key in hashmap:
            keys.add(key)
        self.assertEqual(keys, {"key1", "key2"})

    def test_repr(self):
        hashmap = HashMap()
        hashmap["key1"] = "value1"
        hashmap["key2"] = "value2"
        self.assertEqual(repr(hashmap), "HashMap(key1: value1 ,key2: value2)")

if __name__ == "__main__":
    unittest.main()
```