import unittest

def binomial_coefficient(n, r):
    """
    Find binomial coefficient using pascals triangle.

    >>> binomial_coefficient(10, 5)
    252
    """
    c = [0 for i in range(r + 1)]
    # nc0 = 1
    c[0] = 1
    for i in range(1, n + 1):
        # to compute current row from previous row.
        j = min(i, r)
        while j > 0:
            c[j] += c[j - 1]
            j -= 1
    return c[r]


class TestBinomialCoefficient(unittest.TestCase):
    def test_binomial_coefficient(self):
        self.assertEqual(binomial_coefficient(10, 5), 252)


if __name__ == '__main__':
    unittest.main()