"""Newton's Method."""

# Newton's Method - https://en.wikipedia.org/wiki/Newton%27s_method
from collections.abc import Callable
from typing import Optional

RealFunc = Callable[[float], float]  # type alias for a real -> real function


# function is the f(x) and derivative is the f'(x)
def newton(
    function: RealFunc,
    derivative: RealFunc,
    starting_int: float,
    tolerance: float = 1e-5,
    max_iter: Optional[int] = None
) -> float:
    prev_guess = starting_int
    iteration = 0
    while max_iter is None or iteration < max_iter:
        try:
            next_guess = prev_guess - function(prev_guess) / derivative(prev_guess)
        except ZeroDivisionError:
            raise ZeroDivisionError("Could not find root") from None

        if abs(prev_guess - next_guess) < tolerance:
            return next_guess
        
        prev_guess = next_guess
        iteration += 1

    raise ArithmeticError("The Newton's method did not converge.")


def f(x: float) -> float:
    return (x**3) - (2 * x) - 5


def f1(x: float) -> float:
    return 3 * (x**2) - 2


if __name__ == "__main__":
    print(newton(f, f1, 3.0))