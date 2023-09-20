# Implementing Newton Raphson method in Python

from typing import Complex, Tuple
from sympy import diff, lambdify, symbols

def newton_raphson(
    function: str,
    starting_point: Complex,
    variable: str = "x",
    precision: float = 10**-10,
    multiplicity: int = 1,
) -> Tuple[Complex, int]:
   
    x = symbols(variable)
    func = lambdify(x, function)
    diff_function = lambdify(x, diff(function, x))

    prev_guess = starting_point
    iterations = 0

    while True:
        iterations += 1
        if diff_function(prev_guess) != 0:
            next_guess = prev_guess - multiplicity * func(prev_guess) / diff_function(prev_guess)
        else:
            raise ZeroDivisionError("Could not find root") from None
        
        if abs(next_guess - prev_guess) < precision:
            return next_guess, iterations

        prev_guess = next_guess


# Let's Execute
if __name__ == "__main__":
    print(f"The root of sin(x) = 0 is {newton_raphson('sin(x)', 2)[0]}")
    print(f"The root of x**4 - 5 = 0 is {newton_raphson('x**4 -5', 0.4 +5j)[0]}")
    print(f"The root of log(y) - 1 = 0 is {newton_raphson('log(y) - 1', 2, variable='y')[0]}")
    print(f"The root of exp(x) - 1 = 0 is {newton_raphson('exp(x) - 1', 10, precision=0.005)[0]}")
    print(f"The root of cos(x) = 0 is {newton_raphson('cos(x)', 0)[0]}")