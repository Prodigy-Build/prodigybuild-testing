# Implementing Newton Raphson method in Python

from sympy import diff, lambdify, symbols


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
        except ZeroDivisionError:
            raise ValueError("Could not find root")

        if abs(next_guess - prev_guess) < precision:
            return next_guess

        prev_guess = next_guess


if __name__ == "__main__":
    print(f"The root of sin(x) = 0 is {newton_raphson('sin(x)', 2)}")
    print(f"The root of x**4 - 5 = 0 is {newton_raphson('x**4 -5', 0.4 +5j)}")
    print(f"The root of log(y) - 1 = 0 is {newton_raphson('log(y) - 1', 2, variable='y')}")
    print(f"The root of exp(x) - 1 = 0 is {newton_raphson('exp(x) - 1', 10, precision=0.005)}")
    print(f"The root of cos(x) = 0 is {newton_raphson('cos(x)', 0)}")