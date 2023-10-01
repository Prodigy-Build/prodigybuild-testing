"""Newton's Method."""

# Newton's Method - https://en.wikipedia.org/wiki/Newton%27s_method
from collections.abc import Callable

RealFunc = Callable[[float], float]  # type alias for a real -> real function


# function is the f(x) and derivative is the f'(x)
def newton(
    function: RealFunc,
    derivative: RealFunc,
    starting_int: int,
) -> float:
    """
    >>> newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3)
    2.0945514815423474
    >>> newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2)
    1.0
    >>> newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4)
    1.0000000000000102
    >>> import math
    >>> newton(math.sin, math.cos, 1)
    0.0
    >>> newton(math.sin, math.cos, 2)
    3.141592653589793
    >>> newton(math.cos, lambda x: -math.sin(x), 2)
    1.5707963267948966
    >>> newton(math.cos, lambda x: -math.sin(x), 0)
    Traceback (most recent call last):
        ...
    ZeroDivisionError: Could not find root
    """
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
    assert newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3) == 2.0945514815423474
    assert newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2) == 1.0
    assert newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4) == 1.0000000000000102
    import math
    assert newton(math.sin, math.cos, 1) == 0.0
    assert newton(math.sin, math.cos, 2) == 3.141592653589793
    assert newton(math.cos, lambda x: -math.sin(x), 2) == 1.5707963267948966
    try:
        assert newton(math.cos, lambda x: -math.sin(x), 0) == True
    except ZeroDivisionError as e:
        assert str(e) == "Could not find root"


if __name__ == "__main__":
    test_newton()