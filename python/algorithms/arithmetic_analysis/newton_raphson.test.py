from typing import Union
from decimal import Decimal

def newton_raphson(func: str, a: Union[float, Decimal], precision: float = 10**-10) -> float:
    x = Decimal(a)
    while True:
        x = x - (Decimal(eval(func)) / Decimal(eval(str(diff(func)))))
        if abs(eval(func)) < precision:
            return float(x)

def test_newton_raphson():
    assert abs(newton_raphson("sin(x)", 2) - 3.1415926536808043) < 10**-10
    assert abs(newton_raphson("x**2 - 5*x +2", 0.4) - 0.4384471871911695) < 10**-10
    assert abs(newton_raphson("x**2 - 5", 0.1) - 2.23606797749979) < 10**-10
    assert abs(newton_raphson("log(x) - 1", 2) - 2.718281828458938) < 10**-10

if __name__ == "__main__":
    test_newton_raphson()
    print("All tests passed!")