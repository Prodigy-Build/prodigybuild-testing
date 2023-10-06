"""
Implementing Secant method in Python
Author: dimgrichr
"""
from math import exp


def f(x: float) -> float:
    """
    >>> f(5)
    39.98652410600183
    """
    return 8 * x - 2 * exp(-x)


def secant_method(lower_bound: float, upper_bound: float, repeats: int) -> float:
    """
    >>> secant_method(1, 3, 2)
    0.2139409276214589
    """
    x0 = lower_bound
    x1 = upper_bound
    for _ in range(0, repeats):
        x0, x1 = x1, x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))
    return x1


if __name__ == "__main__":
    print(f"Example: {secant_method(1, 3, 2)}")


# Unit tests
def test_f():
    assert f(5) == 39.98652410600183


def test_secant_method():
    assert secant_method(1, 3, 2) == 0.2139409276214589
    assert secant_method(0, 5, 3) == 0.31299004020556743
    assert secant_method(-10, 10, 5) == -0.35173371124919525
    assert secant_method(-100, 100, 10) == 0.06944167727397202


test_f()
test_secant_method()
