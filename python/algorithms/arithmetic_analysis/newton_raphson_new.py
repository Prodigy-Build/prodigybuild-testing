# Implementing Newton Raphson method in Python
# Author: Saksham Gupta
#
# The Newton-Raphson method (also known as Newton's method) is a way to
# quickly find a good approximation for the root of a real-valued function
# The method can also be extended to complex functions
#
# Newton's Method - https://en.wikipedia.org/wiki/Newton's_method

from sympy import diff, lambdify, symbols
from sympy.functions import *  # noqa: F403

def newton_raphson(
    function: str,
    starting_point: complex,
    *,
    variable: str = "x",
    precision: float = 10**-10,
    multiplicity: int = 1,
) -> complex:
    """Finds root from the 'starting_point' onwards by Newton-Raphson method
    Refer to https://docs.sympy.org/latest/modules/functions/index.html
    for usable mathematical functions
    """

    x = symbols(variable)
    func = lambdify(x, function)
    diff_function = lambdify(x, diff(function, x))

    prev_guess = starting_point

    while True:
        if diff_function(prev_guess) != 0:
            next_guess = prev_guess - multiplicity * func(prev_guess) / diff_function(
                prev_guess
            )
        else:
            raise ZeroDivisionError("Could not find root") 

        # Precision is checked by comparing the difference of consecutive guesses
        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess


# Let's Execute
if __name__ == "__main__":
    print(f"The root of sin(x) = 0 is {newton_raphson('sin(x)', 2)}")
    print(f"The root of x**4 - 5 = 0 is {newton_raphson('x**4 - 5', 0.4 + 5j)}")
    print(
        "The root of log(y) - 1 = 0 is ",
        f"{newton_raphson('log(y) - 1', 2, variable='y')}",
    )
    print(
        "The root of exp(x) - 1 = 0 is",
        f"{newton_raphson('exp(x) - 1', 10, precision=0.005)}",
    )
    print(f"The root of cos(x) = 0 is {newton_raphson('cos(x)', 0)}")