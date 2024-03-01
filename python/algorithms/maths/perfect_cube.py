import unittest

def perfect_cube(n: int) -> bool:
    """
    Check if a number is a perfect cube or not.

    >>> perfect_cube(27)
    True
    >>> perfect_cube(4)
    False
    """
    val = n ** (1 / 3)
    return (val * val * val) == n


class PerfectCubeTestCase(unittest.TestCase):
    def test_perfect_cube(self):
        self.assertTrue(perfect_cube(27))
        self.assertFalse(perfect_cube(4))


if __name__ == "__main__":
    unittest.main()