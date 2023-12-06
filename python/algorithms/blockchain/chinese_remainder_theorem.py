from typing import Tuple

def extended_euclid(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return (1, 0)
    (x, y) = extended_euclid(b, a % b)
    k = a // b
    return (y, x - k * y)

def chinese_remainder_theorem(n1: int, r1: int, n2: int, r2: int) -> int:
    (x, y) = extended_euclid(n1, n2)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m

def invert_modulo(a: int, n: int) -> int:
    (b, x) = extended_euclid(a, n)
    if b < 0:
        b = (b % n + n) % n
    return b

def chinese_remainder_theorem2(n1: int, r1: int, n2: int, r2: int) -> int:
    x, y = invert_modulo(n1, n2), invert_modulo(n2, n1)
    m = n1 * n2
    n = r2 * x * n1 + r1 * y * n2
    return (n % m + m) % m