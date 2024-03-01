from typing import List

def is_square_free(n: int) -> bool:
    """
    Check if a number is square-free
    """
    if n < 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % (i ** 2) == 0:
            return False
    return True


def prime_factors(n: int) -> List[int]:
    """
    Find the prime factors of a number
    """
    factors = []
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def mobius(n: int) -> int:
    """
    Mobius function
    """
    if not isinstance(n, int):
        raise TypeError("Argument must be an integer")
    if n <= 0:
        return 1
    factors = prime_factors(n)
    if is_square_free(factors):
        return -1 if len(factors) % 2 else 1
    return 0


if __name__ == "__main__":
    import doctest

    doctest.testmod()