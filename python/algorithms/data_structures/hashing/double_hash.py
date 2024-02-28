The updated code with unit test cases is as follows:

```python
#!/usr/bin/env python3
"""
Double hashing is a collision resolving technique in Open Addressed Hash tables.
Double hashing uses the idea of applying a second hash function to key when a collision
occurs. The advantage of Double hashing is that it is one of the best form of  probing,
producing a uniform distribution of records throughout a hash table. This technique
does not yield any clusters. It is one of effective method for resolving collisions.

Double hashing can be done using: (hash1(key) + i * hash2(key)) % TABLE_SIZE
Where hash1() and hash2() are hash functions and TABLE_SIZE is size of hash table.

Reference: https://en.wikipedia.org/wiki/Double_hashing
"""
from .hash_table import HashTable
from .number_theory.prime_numbers import is_prime, next_prime


class DoubleHash(HashTable):
    """
    Hash Table example with open addressing and Double Hash
    """

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def __hash_function_2(self, value, data):
        next_prime_gt = (
            next_prime(value % self.size_table)
            if not is_prime(value % self.size_table)
            else value % self.size_table
        )  # gt = bigger than
        return next_prime_gt - (data % next_prime_gt)

    def __hash_double_function(self, key, data, increment):
        return (increment * self.__hash_function_2(key, data)) % self.size_table

    def _collision_resolution(self, key, data=None):
        i = 1
        new_key = self.hash_function(data)

        while self.values[new_key] is not None and self.values[new_key] != key:
            new_key = (
                self.__hash_double_function(key, data, i)
                if self.balanced_factor() >= self.lim_charge
                else None
            )
            if new_key is None:
                break
            else:
                i += 1

        return new_key


import unittest


class DoubleHashTest(unittest.TestCase):
    def test_collision_resolution(self):
        hash_table = DoubleHash(size_table=10)
        hash_table.insert(1, "A")
        hash_table.insert(11, "B")
        hash_table.insert(21, "C")
        hash_table.insert(31, "D")
        hash_table.insert(41, "E")
        hash_table.insert(51, "F")
        hash_table.insert(61, "G")
        hash_table.insert(71, "H")
        hash_table.insert(81, "I")
        hash_table.insert(91, "J")

        self.assertEqual(hash_table.search(1), "A")
        self.assertEqual(hash_table.search(11), "B")
        self.assertEqual(hash_table.search(21), "C")
        self.assertEqual(hash_table.search(31), "D")
        self.assertEqual(hash_table.search(41), "E")
        self.assertEqual(hash_table.search(51), "F")
        self.assertEqual(hash_table.search(61), "G")
        self.assertEqual(hash_table.search(71), "H")
        self.assertEqual(hash_table.search(81), "I")
        self.assertEqual(hash_table.search(91), "J")

    def test_collision_resolution_with_replacement(self):
        hash_table = DoubleHash(size_table=10)
        hash_table.insert(1, "A")
        hash_table.insert(11, "B")
        hash_table.insert(21, "C")
        hash_table.insert(31, "D")
        hash_table.insert(41, "E")
        hash_table.insert(51, "F")
        hash_table.insert(61, "G")
        hash_table.insert(71, "H")
        hash_table.insert(81, "I")
        hash_table.insert(91, "J")
        hash_table.insert(101, "K")

        self.assertEqual(hash_table.search(1), "A")
        self.assertEqual(hash_table.search(11), "B")
        self.assertEqual(hash_table.search(21), "C")
        self.assertEqual(hash_table.search(31), "D")
        self.assertEqual(hash_table.search(41), "E")
        self.assertEqual(hash_table.search(51), "F")
        self.assertEqual(hash_table.search(61), "G")
        self.assertEqual(hash_table.search(71), "H")
        self.assertEqual(hash_table.search(81), "I")
        self.assertEqual(hash_table.search(91), "J")
        self.assertEqual(hash_table.search(101), "K")


if __name__ == "__main__":
    unittest.main()
```
