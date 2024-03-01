from math import pi


def radians(degree: float) -> float:
    """
    Coverts the given angle from degrees to radians
    https://en.wikipedia.org/wiki/Radian
    """
    return degree / (180 / pi)


if __name__ == "__main__":
    from doctest import testmod

    testmod()