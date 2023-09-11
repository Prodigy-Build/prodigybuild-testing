"""
Chinese Remainder Theorem:
GCD ( Greatest Common Divisor ) or HCF ( Highest Common Factor )

If GCD(a,b) = 1, then for any remainder ra modulo a and any remainder rb modulo b
there exists integer n, such that n = ra (mod a) and n = ra(mod b).  If n1 and n2 are
two such integers, then n1=n2(mod ab)

Algorithm :

1. Use extended euclid algorithm to find x,y such that a*x + b*y = 1
2. Take n = ra*by + rb*ax
"""
from __future__ import annotations


# Extended Euclid
from math import gcd

def extended_euclid(a: int, b: int) -> tuple[int, int]:
    """
    >>> extended_euclid(10, 6)
    (-1, 2)

    >>> extended_euclid(7, 5)
    (-2, 3)

    """
    if a == 0:
        return (0, 1)
    else:
        x, y = extended_euclid(b % a, a)
        return (y - (b//a) * x, x)


# Uses ExtendedEuclid to find inverses
def chinese_remainder_theorem(n1: int, r1: int, n2: int, r2: int) -> int:
    """
    >>> chinese_remainder_theorem(5,1,7,3)
    31

    Explanation : 31 is the smallest number such that
                (i)  When we divide it by 5, we get remainder 1
                (ii) When we divide it by 7, we get remainder 3

    >>> chinese_remainder_theorem(6,1,4,3)
    14

    """
    (x, y) = extended_euclid(n1, n2)
    if gcd(n1, n2) != 1:
        return -1
    else:
        return (r1 * n2 * y + r2 * n1 * x) % (n1 * n2)


if __name__ == "__main__":
    from doctest import testmod

    testmod(name="chinese_remainder_theorem", verbose=True)
    testmod(name="extended_euclid", verbose=True)