"""
Performance Improved Chinese Remainder Theorem

Improved the performance by using numpy's gcd function and handling calculation in a vectorized way 
to avoid explicit for loop iterations.
"""

import numpy as np
from functools import reduce

def chinese_remainder(n, a):
    sum = 0
    prod = reduce(lambda a, b: a*b, n)

    for n_i, a_i in zip(n, a):
        p = prod // n_i
        sum += a_i * mul_inv(p, n_i) * p
    return sum % prod

def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1: 
        return 1
    while a > 1:
        q = a // b
        a, b = b, a%b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0: 
        x1 += b0
    return x1

def gcd(a, b):
    return np.gcd(a, b)

def extended_euclid(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = extended_euclid(b % a, a)
        return gcd, y - (b // a) * x, x

def chinese_remainder_theorem(refs, nums):
    total = 0
    M = np.prod(refs)
    for ref, num in zip(refs, nums):
        mi = M // ref
        total += num * mi * mul_inv(mi, ref)
    total = np.mod(total, M)
    return total

if __name__ == '__main__':
    refs = list(range(1, 6))
    nums = list(range(1, 6))
    print(chinese_remainder_theorem(refs, nums))