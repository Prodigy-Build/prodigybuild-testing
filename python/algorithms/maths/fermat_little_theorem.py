def binary_exponentiation(a, n, mod):
    if n == 0:
        return 1

    elif n % 2 == 1:
        return (binary_exponentiation(a, n - 1, mod) * a) % mod

    else:
        b = binary_exponentiation(a, n // 2, mod)
        return (b * b) % mod


# a prime number
p = 701

a = 1000000000
b = 10

# using binary exponentiation function, O(log(p)):
assert (a / b) % p == (a * binary_exponentiation(b, p - 2, p)) % p

# using Python operators:
assert (a / b) % p == (a * b ** (p - 2)) % p