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
from math import gcd

def chinese_remainder_theorem(l: list[tuple[int, int]]) -> int:
    N = 1
    for a, p in l:
        N *= p

    result = 0
    for a, p in l:
        m = N // p
        r, s, d = extended_gcd(p, m)
        if r != 1:
            raise ValueError("Input not pairwise co-prime")
        result += a * s * m
        result %= N  
    return result

def extended_gcd(a: int, b: int) -> tuple[int, int, int]:
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_gcd(b % a, a)
        return (g, y - (b // a) * x, x)
        

if __name__ == "__main__":
    from doctest import testmod

    testmod(name="chinese_remainder_theorem", verbose=True)
    testmod(name="extended_gcd", verbose=True)