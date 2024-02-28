Here is the updated code with unit test cases:

```python
#!/usr/bin/env python3

import unittest
from .hash_table import HashTable


class QuadraticProbing(HashTable):
    """
    Basic Hash Table example with open addressing using Quadratic Probing
    """

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def _collision_resolution(self, key, data=None):
        i = 1
        new_key = self.hash_function(key + i * i)

        while self.values[new_key] is not None and self.values[new_key] != key:
            i += 1
            new_key = (
                self.hash_function(key + i * i)
                if not self.balanced_factor() >= self.lim_charge
                else None
            )

            if new_key is None:
                break

        return new_key


class QuadraticProbingTestCase(unittest.TestCase):
    def setUp(self):
        self.hash_table = QuadraticProbing()

    def test_collision_resolution(self):
        self.hash_table.insert(1, "A")
        self.hash_table.insert(2, "B")
        self.hash_table.insert(3, "C")
        self.hash_table.insert(4, "D")
        self.hash_table.insert(5, "E")
        self.hash_table.insert(6, "F")
        self.hash_table.insert(7, "G")
        self.hash_table.insert(8, "H")
        self.hash_table.insert(9, "I")
        self.hash_table.insert(10, "J")

        # Key 1 should be at index 1
        self.assertEqual(self.hash_table._collision_resolution(1), 1)

        # Key 2 should be at index 2
        self.assertEqual(self.hash_table._collision_resolution(2), 2)

        # Key 3 should be at index 3
        self.assertEqual(self.hash_table._collision_resolution(3), 3)

        # Key 4 should be at index 4
        self.assertEqual(self.hash_table._collision_resolution(4), 4)

        # Key 5 should be at index 5
        self.assertEqual(self.hash_table._collision_resolution(5), 5)

        # Key 6 should be at index 6
        self.assertEqual(self.hash_table._collision_resolution(6), 6)

        # Key 7 should be at index 7
        self.assertEqual(self.hash_table._collision_resolution(7), 7)

        # Key 8 should be at index 8
        self.assertEqual(self.hash_table._collision_resolution(8), 8)

        # Key 9 should be at index 9
        self.assertEqual(self.hash_table._collision_resolution(9), 9)

        # Key 10 should be at index 0 (wrap around)
        self.assertEqual(self.hash_table._collision_resolution(10), 0)


if __name__ == "__main__":
    unittest.main()
```

Note: The original code provided in the question is not testable as it is missing the implementation of the `HashTable` class and the `hash_function` method. I have assumed that those parts are implemented correctly in the `hash_table.py` file.