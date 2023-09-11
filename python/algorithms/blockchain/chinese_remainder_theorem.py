

"""
Implementation of the Chinese Remainder Theorem

Uses GCD (Greatest Common Divisor) to determine an integer n such that n gives specific remainders 
when divided by given numbers. If a and b have GCD 1, for any remainders ra modulo a and rb modulo b,
there exists integer n that equals ra (mod a) and rb(mod b).

Algorithm :
1. Utilize the extended Euclid algorithm to find x,y such that a*x + b*y = 1
2. Define n = ra*by + rb*ax
"""
from typing import Tuple

def extended_euclid(a: int, b: int) -> Tuple[int, int]:
    """
    Use Extended Euclid's Algorithm to find x, y such that ax + by = 1
    """
    if b == 0:
        return (1, 0)
    
    (x, y) = extended_euclid(b, a % b)
    return (y, x - (a // b) * y)


def chinese_remainder_theorem(n1: int, r1: int, n2: int, r2: int) -> int:
    """
    Returns smallest number n that has remainder r1 modulo n1 and r2 modulo n2.
    """
    (x, y) = extended_euclid(n1, n2)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m


def invert_modulo(a: int, n: int) -> int:
    """
    Find the inverse of a modulo n
    """
    (b, _) = extended_euclid(a, n)
    return (b % n + n) % n


def chinese_remainder_theorem_alternative(n1: int, r1: int, n2: int, r2: int) -> int:
    """
    Alternative solution to the Chinese Remainder Theorem problem, using invert_modulo function.
    """
    x, y = invert_modulo(n1, n2), invert_modulo(n2, n1)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m


if __name__ == "__main__":
    from doctest import testmod

    testmod(name="chinese_remainder_theorem", verbose=True)
    testmod(name="chinese_remainder_theorem_alternative", verbose=True)
    testmod(name="invert_modulo", verbose=True)
    testmod(name="extended_euclid", verbose=True)

