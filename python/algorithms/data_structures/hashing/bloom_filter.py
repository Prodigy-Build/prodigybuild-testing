The updated code with unit test cases is as follows:

```python
import unittest
from hashlib import md5, sha256
from typing import Tuple

HASH_FUNCTIONS = (sha256, md5)


class Bloom:
    def __init__(self, size: int = 8) -> None:
        self.bitarray = 0b0
        self.size = size

    def add(self, value: str) -> None:
        h = self.hash_(value)
        self.bitarray |= h

    def exists(self, value: str) -> bool:
        h = self.hash_(value)
        return (h & self.bitarray) == h

    def __contains__(self, other: str) -> bool:
        return self.exists(other)

    def format_bin(self, bitarray: int) -> str:
        res = bin(bitarray)[2:]
        return res.zfill(self.size)

    @property
    def bitstring(self) -> str:
        return self.format_bin(self.bitarray)

    def hash_(self, value: str) -> int:
        res = 0b0
        for func in HASH_FUNCTIONS:
            position = (
                int.from_bytes(func(value.encode()).digest(), "little") % self.size
            )
            res |= 2**position
        return res

    def format_hash(self, value: str) -> str:
        return self.format_bin(self.hash_(value))

    @property
    def estimated_error_rate(self) -> float:
        n_ones = bin(self.bitarray).count("1")
        return (n_ones / self.size) ** len(HASH_FUNCTIONS)


class BloomFilterTestCase(unittest.TestCase):
    def test_add_and_exists(self):
        bloom = Bloom(size=8)
        self.assertFalse("Titanic" in bloom)
        bloom.add("Titanic")
        self.assertTrue("Titanic" in bloom)
        self.assertTrue(bloom.exists("Titanic"))

    def test_multiple_add_and_exists(self):
        bloom = Bloom(size=8)
        self.assertFalse("Titanic" in bloom)
        self.assertFalse("Avatar" in bloom)
        bloom.add("Titanic")
        bloom.add("Avatar")
        self.assertTrue("Titanic" in bloom)
        self.assertTrue("Avatar" in bloom)
        self.assertTrue(bloom.exists("Titanic"))
        self.assertTrue(bloom.exists("Avatar"))

    def test_format_bin(self):
        bloom = Bloom(size=8)
        self.assertEqual(bloom.format_bin(0b0), "00000000")
        self.assertEqual(bloom.format_bin(0b1), "00000001")
        self.assertEqual(bloom.format_bin(0b10), "00000010")
        self.assertEqual(bloom.format_bin(0b11), "00000011")
        self.assertEqual(bloom.format_bin(0b101), "00000101")

    def test_bitstring(self):
        bloom = Bloom(size=8)
        self.assertEqual(bloom.bitstring, "00000000")
        bloom.add("Titanic")
        self.assertEqual(bloom.bitstring, "01100000")
        bloom.add("Avatar")
        self.assertEqual(bloom.bitstring, "01100100")

    def test_format_hash(self):
        bloom = Bloom(size=8)
        self.assertEqual(bloom.format_hash("Avatar"), "00000100")
        self.assertEqual(bloom.format_hash("The Godfather"), "00000101")
        self.assertEqual(bloom.format_hash("Interstellar"), "00000011")
        self.assertEqual(bloom.format_hash("Parasite"), "00010010")
        self.assertEqual(bloom.format_hash("Pulp Fiction"), "10000100")

    def test_estimated_error_rate(self):
        bloom = Bloom(size=8)
        self.assertAlmostEqual(bloom.estimated_error_rate, 0.140625)
        bloom.add("The Godfather")
        self.assertAlmostEqual(bloom.estimated_error_rate, 0.25)


if __name__ == "__main__":
    unittest.main()
```
