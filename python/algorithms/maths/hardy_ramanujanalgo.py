import unittest
import math


def exact_prime_factor_count(n):
    count = 0
    if n % 2 == 0:
        count += 1
        while n % 2 == 0:
            n = int(n / 2)

    i = 3

    while i <= int(math.sqrt(n)):
        if n % i == 0:
            count += 1
            while n % i == 0:
                n = int(n / i)
        i = i + 2

    if n > 2:
        count += 1
    return count


class TestExactPrimeFactorCount(unittest.TestCase):
    def test_exact_prime_factor_count(self):
        self.assertEqual(exact_prime_factor_count(51242183), 3)


if __name__ == "__main__":
    unittest.main()