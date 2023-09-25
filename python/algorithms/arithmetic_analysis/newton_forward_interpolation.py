from typing import List
import math

def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp

def newton_forward_interpolation(x: List[int], y: List[float], value: int) -> float:
    n = len(x)
    u = (value - x[0]) / (x[1] - x[0])

    # for calculating forward difference table
    for i in range(1, n):
        for j in range(n - i):
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

    summ = y[0][0]
    for i in range(1, n):
        summ += (ucal(u, i) * y[0][i]) / math.factorial(i)

    return summ

# Unit tests
x = [1, 2, 3, 4]
y = [f(x) for x in x] # Define your own function f(x)
assert math.isclose(newton_forward_interpolation(x, y, 2.5), f(2.5))