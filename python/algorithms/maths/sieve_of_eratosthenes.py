The new code for the file "python/algorithms/maths/sieve_of_eratosthenes.py" is:

```python
from typing import List
import math


def prime_sieve(num: int) -> List[int]:
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
    primes = []
    start = 2
    end = int(math.sqrt(num))

    while start <= end:
        if sieve[start]:
            primes.append(start)
            for i in range(start * start, num + 1, start):
                sieve[i] = False
        start += 1

    for j in range(end + 1, num + 1):
        if sieve[j]:
            primes.append(j)

    return primes


if __name__ == "__main__":
    print(prime_sieve(int(input("Enter a positive integer: ").strip())))
```