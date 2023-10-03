from __future__ import annotations
from typing import Tuple
from math import gcd

def modular_division(a: int, b: int, n: int) -> int:
    (d, t, s) = extended_gcd(n, a)
    x = (b * s) % n
    return x

def invert_modulo(a: int, n: int) -> int:
    (b, x) = extended_euclid(a, n)
    if b < 0:
        b = (b % n + n) % n
    return b

def modular_division2(a: int, b: int, n: int) -> int:
    s = invert_modulo(a, n)
    x = (b * s) % n
    return x

def extended_gcd(a: int, b: int) -> Tuple[int, int, int]:
    if b == 0:
        d, x, y = a, 1, 0
    else:
        (d, p, q) = extended_gcd(b, a % b)
        x = q
        y = p - q * (a // b)
    return (d, x, y)

def extended_euclid(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return (1, 0)
    (x, y) = extended_euclid(b, a % b)
    k = a // b
    return (y, x - k * y)

def greatest_common_divisor(a: int, b: int) -> int:
    while a % b != 0:
        a, b = b, a % b
    return b