from typing import Callable
import math

RealFunc = Callable[[float], float]

def newton(
    function: RealFunc,
    derivative: RealFunc,
    starting_int: int,
) -> float:
    prev_guess = float(starting_int)
    while True:
        try:
            next_guess = prev_guess - function(prev_guess) / derivative(prev_guess)
        except ZeroDivisionError:
            raise ZeroDivisionError("Could not find root") from None
        if abs(prev_guess - next_guess) < 10**-5:
            return next_guess
        prev_guess = next_guess

def test_newton():
    assert math.isclose(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3), 2.0945514815423474)
    assert math.isclose(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2), 1.0)
    assert math.isclose(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4), 1.0000000000000102)
    assert math.isclose(newton(math.sin, math.cos, 1), 0.0)
    assert math.isclose(newton(math.sin, math.cos, 2), 3.141592653589793)
    assert math.isclose(newton(math.cos, lambda x: -math.sin(x), 2), 1.5707963267948966)
    try:
        newton(math.cos, lambda x: -math.sin(x), 0)
    except ZeroDivisionError:
        pass

if __name__ == "__main__":
    test_newton()