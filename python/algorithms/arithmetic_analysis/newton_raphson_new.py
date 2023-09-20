# Implementing Newton Raphson method in Python
# Author: Saksham Gupta
#
# The Newton-Raphson method is a method to quickly find a good approximation for the root of real-valued function
# This method can also be extended to complex functions

from sympy import diff, lambdify, symbols
from sympy.functions import *

def newton_raphson(
    function: str,
    starting_point: complex,
    variable: str = "x",
    precision: float = 1e-10,
    multiplicity: int = 1,
) -> complex:

    x = symbols(variable)
    func = lambdify(x, function)
    diff_function = lambdify(x, diff(function, x))

    prev_guess = starting_point

    while True:
        try:
            next_guess = prev_guess - multiplicity * func(prev_guess) / diff_function(
                prev_guess
            ) 
        except ZeroDivisionError as e:
            raise ZeroDivisionError("Could not find root") from e
            
        # checking precision
        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess


if __name__ == "__main__":
    print(f"The root of sin(x) = 0 is {newton_raphson('sin(x)', 2)}")

    print(f"The root of x**4 - 5 = 0 is {newton_raphson('x**4 -5', 0.4 +5j)}")

    print(
        "The root of log(y) - 1 = 0 is ",
        f"{newton_raphson('log(y) - 1', 2, variable='y')}",
    )

    print(
        "The root of exp(x) - 1 = 0 is",
        f"{newton_raphson('exp(x) - 1', 10, precision=0.005)}",
    )

    try:
        print(f"The root of cos(x) = 0 is {newton_raphson('cos(x)', 0)}")
    except ZeroDivisionError as e:
        print("Could not find root: ", e)
