from decimal import Decimal
from math import *
from sympy import diff


def newton_raphson(
    func: str, a: float | Decimal, precision: float = 10**-10
) -> float:
    """Finds root from the point 'a' onwards by Newton-Raphson method"""
    x = a
    while True:
        x = Decimal(x) - (Decimal(eval(func)) / Decimal(eval(str(diff(func)))))
        if abs(eval(func)) < precision:
            return float(x)