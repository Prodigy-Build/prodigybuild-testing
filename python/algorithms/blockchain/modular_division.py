from typing import Tuple
def modular_division(a: int, b: int, n: int) -> int:
    return (b * invert_modulo(a, n)) % n

def invert_modulo(a: int, n: int) -> int:
    return extended_euclid(a, n)[0]

def extended_euclid(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return (1, 0)
    (x, y) = extended_euclid(b, a % b)
    k = a // b
    return (y, x - k * y)