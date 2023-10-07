import math
import unittest
from typing import List

def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp

def newton_forward_interpolation(n: int, y: List[List[float]], x: List[float], value: float) -> float:
    u = (value - x[0]) / (x[1] - x[0])

    for i in range(1, n):
        for j in range(n - i):
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

    summ = y[0][0]
    for i in range(1, n):
        summ += (ucal(u, i) * y[0][i]) / math.factorial(i)

    return summ

class TestNewtonForwardInterpolation(unittest.TestCase):

    def test_newton_forward_interpolation(self):
        n = 4
        y = [[0 for _ in range(n)] for _ in range(n)]
        x = [1, 2, 3, 4]
        for i in range(n):
            y[i][0] = 2 ** i
        
        value = 0.5

        result = newton_forward_interpolation(n, y, x, value)
        self.assertAlmostEqual(result, 0.12109375)

        value = 1.5
        result = newton_forward_interpolation(n, y, x, value)
        self.assertAlmostEqual(result, 2.421875)
        
        value = 2.5
        result = newton_forward_interpolation(n, y, x, value)
        self.assertAlmostEqual(result, 6.921875)

unittest.main()