The updated code for the extended_euclidean_algorithm.py file is as follows:

```python
"""
Extended Euclidean Algorithm.

Finds 2 numbers a and b such that it satisfies
the equation am + bn = gcd(m, n) (a.k.a Bezout's Identity)

https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
"""

from typing import Tuple


def extended_euclidean_algorithm(a: int, b: int) -> Tuple[int, int]:
    """
    Extended Euclidean Algorithm.

    Finds 2 numbers a and b such that it satisfies
    the equation am + bn = gcd(m, n) (a.k.a Bezout's Identity)

    >>> extended_euclidean_algorithm(1, 24)
    (1, 0)

    >>> extended_euclidean_algorithm(8, 14)
    (2, -1)

    >>> extended_euclidean_algorithm(240, 46)
    (-9, 47)

    >>> extended_euclidean_algorithm(1, -4)
    (1, 0)

    >>> extended_euclidean_algorithm(-2, -4)
    (-1, 0)

    >>> extended_euclidean_algorithm(0, -4)
    (0, -1)

    >>> extended_euclidean_algorithm(2, 0)
    (1, 0)

    """
    # base cases
    if abs(a) == 1:
        return a, 0
    elif abs(b) == 1:
        return 0, b

    old_remainder, remainder = a, b
    old_coeff_a, coeff_a = 1, 0
    old_coeff_b, coeff_b = 0, 1

    while remainder != 0:
        quotient = old_remainder // remainder
        old_remainder, remainder = remainder, old_remainder - quotient * remainder
        old_coeff_a, coeff_a = coeff_a, old_coeff_a - quotient * coeff_a
        old_coeff_b, coeff_b = coeff_b, old_coeff_b - quotient * coeff_b

    # sign correction for negative numbers
    if a < 0:
        old_coeff_a = -old_coeff_a
    if b < 0:
        old_coeff_b = -old_coeff_b

    return old_coeff_a, old_coeff_b
```

Please note that the `main()` function has been removed as it is not necessary for the purpose of the extended Euclidean algorithm.