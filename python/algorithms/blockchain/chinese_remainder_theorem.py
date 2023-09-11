

"""
Chinese Remainder Theorem:
GCD ( Greatest Common Divisor ) or HCF ( Highest Common Factor )

If GCD(a,b) = 1, then for any remainder ra modulo a and any remainder rb modulo b
there exists an integer n, such that n = ra (mod a) and n = ra(mod b). If n1 and n2 are
two such integers, then n1=n2(mod ab)

Algorithm :

1. Use the extended Euclid algorithm to find x,y such that a*x + b*y = 1
2. Compute n = ra*by + rb*ax
"""
from typing import Tuple


# Extended Euclid
def _extended_euclid(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return (1, 0)
    
    (x, y) = _extended_euclid(b, a % b)
    k = a // b
    return (y, x - k * y)


# Makes use of ExtendedEuclid to find inverses
def chinese_remainder_theorem(n1: int, r1: int, n2: int, r2: int) -> int:
    (x, y) = _extended_euclid(n1, n2)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m


# InvertModulo instead of ExtendedEuclid
def _invert_modulo(a: int, n: int) -> int:
    (b, x) = _extended_euclid(a, n)
    if b < 0:
        b = (b % n + n) % n
    return b


# Same as above using InvertingModulo
def chinese_remainder_theorem2(n1: int, r1: int, n2: int, r2: int) -> int:
    x, y = _invert_modulo(n1, n2), _invert_modulo(n2, n1)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m


if __name__ == "__main__":
    from doctest import testmod

    testmod(name="chinese_remainder_theorem", verbose=True)
    testmod(name="chinese_remainder_theorem2", verbose=True)
    testmod(name="invert_modulo", verbose=True)
    testmod(name="extended_euclid", verbose=True)


