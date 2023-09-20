# Implementing Newton Raphson method in Python

from typing import Any
from sympy import diff, lambdify, symbols

def newton_raphson(
    function: str,
    starting_point: Any,
    variable: str = "x",
    precision: float = 10**-10,
    multiplicity: int = 1,
) -> Any:

    x = symbols(variable)
    diff_function = lambdify(x, diff(function))

    prev_guess = starting_point

    while True:
        diff_guess = diff_function(prev_guess)
        if diff_guess != 0:
            next_guess = prev_guess - multiplicity * function(prev_guess) / diff_guess
        else:
            raise ZeroDivisionError("Could not find root") from None

        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess


if __name__ == "__main__":
    print(f"The root of sin(x) = 0 is {newton_raphson('sin(x)', 2)}")
    print(f"The root of x**4 - 5 = 0 is {newton_raphson('x**4 -5', 0.4 + 5j)}")
    print(f"The root of log(y) - 1 = 0 is {newton_raphson('log(y) - 1', 2, variable='y')}")
    print(f"The root of exp(x) - 1 = 0 is {newton_raphson('exp(x) - 1', 10, precision=0.005)}")
    print(f"The root of cos(x) = 0 is {newton_raphson('cos(x)', 0)}")