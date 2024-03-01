import math
import unittest

def perfect_square(num: int) -> bool:
    """
    Check if a number is perfect square number or not
    :param num: the number to be checked
    :return: True if number is square number, otherwise False
    """
    return math.isqrt(num) ** 2 == num

def perfect_square_binary_search(n: int) -> bool:
    """
    Check if a number is perfect square using binary search.
    Time complexity : O(Log(n))
    Space complexity: O(1)
    """
    if not isinstance(n, int) or n < 0:
        return False
    left = 0
    right = n
    while left <= right:
        mid = (left + right) // 2
        if mid**2 == n:
            return True
        elif mid**2 > n:
            right = mid - 1
        else:
            left = mid + 1
    return False

class PerfectSquareTestCase(unittest.TestCase):
    def test_perfect_square(self):
        self.assertTrue(perfect_square(9))
        self.assertTrue(perfect_square(16))
        self.assertTrue(perfect_square(1))
        self.assertTrue(perfect_square(0))
        self.assertFalse(perfect_square(10))

    def test_perfect_square_binary_search(self):
        self.assertTrue(perfect_square_binary_search(9))
        self.assertTrue(perfect_square_binary_search(16))
        self.assertTrue(perfect_square_binary_search(1))
        self.assertTrue(perfect_square_binary_search(0))
        self.assertFalse(perfect_square_binary_search(10))
        self.assertFalse(perfect_square_binary_search(-1))
        self.assertFalse(perfect_square_binary_search(1.1))
        self.assertFalse(perfect_square_binary_search("a"))
        self.assertFalse(perfect_square_binary_search(None))
        self.assertFalse(perfect_square_binary_search([]))

if __name__ == "__main__":
    unittest.main()