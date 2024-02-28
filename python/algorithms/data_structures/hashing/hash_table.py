import unittest
from number_theory.prime_numbers import next_prime
from hashing.hash_table import HashTable

class TestHashTable(unittest.TestCase):

    def setUp(self):
        self.hash_table = HashTable(10)

    def test_insert_data(self):
        self.hash_table.insert_data(15)
        self.assertEqual(self.hash_table.values[5], 15)
        self.assertEqual(self.hash_table._keys[5], 15)
        self.hash_table.insert_data(25)
        self.assertEqual(self.hash_table.values[5], 15)
        self.assertEqual(self.hash_table.values[5], 25)
        self.assertEqual(self.hash_table._keys[5], 15)
        self.assertEqual(self.hash_table._keys[5], 25)

    def test_collision_resolution(self):
        self.hash_table.insert_data(15)
        self.hash_table.insert_data(25)
        collision_key = self.hash_table._collision_resolution(5, 35)
        self.assertEqual(self.hash_table.values[collision_key], None)
        self.assertEqual(self.hash_table._keys.get(collision_key), None)
        
    def test_rehashing(self):
        for i in range(11):
            self.hash_table.insert_data(i)
        self.assertEqual(self.hash_table.size_table, next_prime(10, factor=2))
        self.assertEqual(len(self.hash_table.values), self.hash_table.size_table)
        self.assertTrue(all(isinstance(key, int) for key in self.hash_table._keys.keys()))
        self.assertTrue(all(value is not None for value in self.hash_table._keys.values()))


if __name__ == '__main__':
    unittest.main()