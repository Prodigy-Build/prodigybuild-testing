# updated python code
from typing import Callable
import math


def intersection(function: Callable[[float], float], x0: float, x1: float) -> float:
    x_n: float = x0
    x_n1: float = x1
    while True:
        try:
            x_n2: float = x_n1 - (
                function(x_n1) / ((function(x_n1) - function(x_n)) / (x_n1 - x_n))
            )
        except ZeroDivisionError:
            raise Exception("float division by zero, could not find root")
        if abs(x_n2 - x_n1) < 1e-5:
            return x_n2
        x_n = x_n1
        x_n1 = x_n2


def f(x: float) -> float:
    return math.pow(x, 3) - (2 * x) - 5


if __name__ == "__main__":
    print(intersection(f, 3, 3.5))