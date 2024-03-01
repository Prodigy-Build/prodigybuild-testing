The updated code for the file "python/algorithms/maths/sieve_of_eratosthenes.py" with added unit test cases is as follows:

```python
"""
Sieve of Eratosthones

The sieve of Eratosthenes is an algorithm used to find prime numbers, less than or
equal to a given value.
Illustration:
https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif
Reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

doctest provider: Bruno Simas Hadlich (https://github.com/brunohadlich)
Also thanks to Dmitry (https://github.com/LizardWizzard) for finding the problem
"""
from __future__ import annotations

import math
import unittest


def prime_sieve(num: int) -> list[int]:
    """
    Returns a list with all prime numbers up to n.

    >>> prime_sieve(50)
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
    >>> prime_sieve(25)
    [2, 3, 5, 7, 11, 13, 17, 19, 23]
    >>> prime_sieve(10)
    [2, 3, 5, 7]
    >>> prime_sieve(9)
    [2, 3, 5, 7]
    >>> prime_sieve(2)
    [2]
    >>> prime_sieve(1)
    []
    """

    if num <= 0:
        msg = f"{num}: Invalid input, please enter a positive integer."
        raise ValueError(msg)

    sieve = [True] * (num + 1)
    prime = []
    start = 2
    end = int(math.sqrt(num))

    while start <= end:
        # If start is a prime
        if sieve[start] is True:
            prime.append(start)

            # Set multiples of start be False
            for i in range(start * start, num + 1, start):
                if sieve[i] is True:
                    sieve[i] = False

        start += 1

    for j in range(end + 1, num + 1):
        if sieve[j] is True:
            prime.append(j)

    return prime


class TestPrimeSieve(unittest.TestCase):
    def test_prime_sieve(self):
        self.assertEqual(prime_sieve(50), [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47])
        self.assertEqual(prime_sieve(25), [2, 3, 5, 7, 11, 13, 17, 19, 23])
        self.assertEqual(prime_sieve(10), [2, 3, 5, 7])
        self.assertEqual(prime_sieve(9), [2, 3, 5, 7])
        self.assertEqual(prime_sieve(2), [2])
        self.assertEqual(prime_sieve(1), [])

    def test_prime_sieve_invalid_input(self):
        with self.assertRaises(ValueError):
            prime_sieve(0)
        with self.assertRaises(ValueError):
            prime_sieve(-10)


if __name__ == "__main__":
    unittest.main()
```
