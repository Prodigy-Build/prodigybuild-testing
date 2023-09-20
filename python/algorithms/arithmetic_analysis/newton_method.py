"""Newton's Method."""

# Newton's Method - https://en.wikipedia.org/wiki/Newton%27s_method
from collections.abc import Callable
from typing import Tuple

RealFunc = Callable[[float], float]  # type alias for a real -> real function


# function is the f(x) and derivative is the f'(x)
def newton(
    function: RealFunc,
    derivative: RealFunc,
    starting_int: float,
    tolerance: float = 1e-5,
    max_iter: int = 100
) -> Tuple[float, int]:
    
    x = starting_int
    for _ in range(max_iter):
        fx = function(x)
        if abs(fx) < tolerance:
            return x
        fpx = derivative(x)
        if abs(fpx) < tolerance:
            raise ZeroDivisionError("Could not find root")
        x -= fx/fpx
    else:
        raise Exception(f"Failed to find root in {max_iter} iterations.")


if __name__ == "__main__":
    # Function and its derivative
    f = lambda x: (x**3) - (2 * x) - 5
    fpx = lambda x: 3 * (x**2) - 2

    # Invoke newton method with starting_int as 3
    try:
        root, iterations = newton(f, fpx, 3)
        print(f"Root: {root:.5f} (found in {iterations} iterations)")
    except Exception as e:
        print(str(e))
