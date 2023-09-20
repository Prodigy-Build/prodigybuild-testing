# Implementing Newton Raphson method in Python

from sympy import diff, lambdify, symbols

def newton_raphson(
    function: str,
    starting_point: complex,
    variable: str = "x",
    precision: float = 10**-10,
    multiplicity: int = 1,
) -> complex:
    """Finds root from the 'starting_point' onwards by Newton-Raphson method
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
            raise ZeroDivisionError("Could not find root") from None

        # Precision is checked by comparing the difference of consecutive guesses
        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess

# Execution
if __name__ == "__main__":
    # Find value of pi
    print(newton_raphson('sin(x)', 2))

    # Find fourth Root of 5
    print(newton_raphson('x**4 -5', 0.4 +5j))

    # Find value of e
    print(newton_raphson('log(y) - 1', 2, variable='y'))

    # Exponential Roots
    print(newton_raphson('exp(x) - 1', 10, precision=0.005))

    # Find root of cos(x)
    print(newton_raphson('cos(x)', 0))