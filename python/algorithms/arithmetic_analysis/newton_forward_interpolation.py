# The code already seems to work with the latest version of Python, so no changes are necessary.
# If you want to specify that it should work with Python 3, you can add a shebang line at the top of the script following way:

#!/usr/bin/env python3

from typing import List, Union
import math

def ucal(u: float, p: int) -> float:
    temp = u
    for i in range(1, p):
        temp = temp * (u - i)
    return temp

def main() -> None:
    n = int(input("enter the numbers of values: "))
    y: List[List[float]] = [[0] * n for _ in range(n)]

    print("enter the values of parameters in a list: ")
    x = list(map(int, input().split()))

    print("enter the values of corresponding parameters: ")
    for i in range(n):
        y[i][0] = float(input())

    value = int(input("enter the value to interpolate: "))
    u = (value - x[0]) / (x[1] - x[0])

    for i in range(1, n):
        for j in range(n - i):
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

    summ = y[0][0]
    for i in range(1, n):
        summ += (ucal(u, i) * y[0][i]) / math.factorial(i)

    print(f"the value at {value} is {summ}")

if __name__ == "__main__":
    main()