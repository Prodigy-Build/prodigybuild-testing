from __future__ import annotations

import math


def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp

def calculate_interpolation(n: int, x: list[int], y: list[float], value: int) -> float:
    result = 0.0
    
    u = (value - x[0]) / (x[1] - x[0])

    for i in range(1, n):
        for j in range(n - i):
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

    summ = y[0][0]
    
    for i in range(1, n):
        summ += (ucal(u, i) * y[0][i]) / math.factorial(i)

    return summ


def main() -> None:
    n = int(input("enter the numbers of values: "))
    y: list[list[float]] = []
    for _ in range(n):
        y.append([])

    print("enter the values of parameters in a list: ")
    x = list(map(int, input().split()))

    print("enter the values of corresponding parameters: ")
    for i in range(n):
        y[i].append(float(input()))

    value = int(input("enter the value to interpolate: "))

    result = calculate_interpolation(n, x, y, value)
    print(f"the value at {value} is {result}")


if __name__ == "__main__":
    main()