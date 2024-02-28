import unittest
from .double_hash import DoubleHash

class TestDoubleHash(unittest.TestCase):
    def setUp(self):
        self.hash_table = DoubleHash()

    def test_collision_resolution(self):
        key1, data1 = "key1", "value1"
        key1_hash = self.hash_table.hash_function(data1)
        self.hash_table.values[key1_hash] = key1

        key2, data2 = "key2", "value2"
        key2_hash = self.hash_table.hash_function(data2)
        self.hash_table.values[key2_hash] = key2

        self.assertEqual(self.hash_table._collision_resolution(key1, data1), key1_hash)
        self.assertNotEqual(self.hash_table._collision_resolution(key2, data2), key2_hash)

    def test_hash_double_function(self):
        key1, data1 = "key1", "value1"
        key2, data2 = "key2", "value2"
        increment = 1
        self.assertNotEqual(
            self.hash_table._DoubleHash__hash_double_function(key1, data1, increment),
            self.hash_table._DoubleHash__hash_double_function(key2, data2, increment),
        )

    def test_hash_function_2(self):
        value = 12
        data = "some data"
        self.assertIsInstance(
            self.hash_table._DoubleHash__hash_function_2(value, data), int
        )

if __name__ == '__main__':
    unittest.main()