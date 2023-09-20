from typing import Callable

def bisection(function: Callable[[float], float], a: float, b: float) -> float:
    start, end = a, b
    if function(a) == 0:  # a is a root for the function
        return a
    elif function(b) == 0:  # b is root for the function
        return b
    elif function(a) * function(b) > 0:
        raise ValueError("No root found within given interval.")
    else:
        mid = start + (end - start) / 2.0
        while abs(start - mid) > 1e-7:  # until difference is ~ 0
            if function(mid) == 0:
                return mid  # mid is root for the function
            elif function(mid) * function(start) < 0:
                end = mid
            else:
                start = mid
            mid = start + (end - start) / 2.0
        return mid

def f(x: float) -> float:
    return x**3 - 2 * x - 5

if __name__ == "__main__":
    print(bisection(f, 1, 1000))

    import doctest
    doctest.testmod()