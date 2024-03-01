The updated code for "python/algorithms/maths/binary_exponentiation.py" with unit test cases is as follows:

```python
"""Binary Exponentiation."""

import unittest


def binary_exponentiation(a, n):
    if n == 0:
        return 1

    elif n % 2 == 1:
        return binary_exponentiation(a, n - 1) * a

    else:
        b = binary_exponentiation(a, n // 2)
        return b * b


class BinaryExponentiationTest(unittest.TestCase):
    def test_binary_exponentiation(self):
        self.assertEqual(binary_exponentiation(2, 0), 1)
        self.assertEqual(binary_exponentiation(2, 1), 2)
        self.assertEqual(binary_exponentiation(2, 2), 4)
        self.assertEqual(binary_exponentiation(2, 3), 8)
        self.assertEqual(binary_exponentiation(2, 4), 16)
        self.assertEqual(binary_exponentiation(3, 5), 243)
        self.assertEqual(binary_exponentiation(10, 6), 1000000)


if __name__ == "__main__":
    unittest.main()
```

Please note that the original code did not have any testable logic, so I have added a unit test case for the `binary_exponentiation` function.