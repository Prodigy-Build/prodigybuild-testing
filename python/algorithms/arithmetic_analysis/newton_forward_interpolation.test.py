from typing import List
import math

def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp

def newton_forward_interpolation(x: List[float], y: List[List[float]], value: float) -> float:
    n = len(x)
    u = (value - x[0]) / (x[1] - x[0])

    for i in range(1, n):
        for j in range(n - i):
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

    summ = y[0][0]
    for i in range(1, n):
        summ += (ucal(u, i) * y[0][i]) / math.factorial(i)

    return summ

if __name__ == "__main__":
    x = [1, 2, 3, 4, 5]
    y = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    for i in range(len(x)):
        for j in range(len(y)):
            y[i][j] = float(input())

    value = float(input("enter the value to interpolate: "))

    result = newton_forward_interpolation(x, y, value)
    print(f"the value at {value} is {result}")