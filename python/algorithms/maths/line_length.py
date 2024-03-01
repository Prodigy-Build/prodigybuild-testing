from __future__ import annotations

import math
from collections.abc import Callable


def line_length(
    fnc: Callable[[int | float], int | float],
    x_start: int | float,
    x_end: int | float,
    steps: int = 100,
) -> float:
    """
    Approximates the arc length of a line segment by treating the curve as a
    sequence of linear lines and summing their lengths
    :param fnc: a function which defines a curve
    :param x_start: left end point to indicate the start of line segment
    :param x_end: right end point to indicate end of line segment
    :param steps: an accuracy gauge; more steps increases accuracy
    :return: a float representing the length of the curve
    """

    x1 = x_start
    fx1 = fnc(x_start)
    length = 0.0

    for _ in range(steps):
        # Approximates curve as a sequence of linear lines and sums their length
        x2 = (x_end - x_start) / steps + x1
        fx2 = fnc(x2)
        length += math.hypot(x2 - x1, fx2 - fx1)

        # Increment step
        x1 = x2
        fx1 = fx2

    return length


if __name__ == "__main__":

    def f(x):
        return math.sin(10 * x)

    print("f(x) = sin(10 * x)")
    print("The length of the curve from x = -10 to x = 10 is:")
    i = 10
    while i <= 100000:
        print(f"With {i} steps: {line_length(f, -10, 10, i)}")
        i *= 10