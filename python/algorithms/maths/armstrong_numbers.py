from typing import Tuple

PASSING: Tuple[int, ...] = (1, 153, 370, 371, 1634, 24678051, 115132219018763992565095597973971522401)
FAILING: Tuple[int, ...] = (-153, -1, 0, 1.2, 200, "A", [], {}, None)


def armstrong_number(n: int) -> bool:
    if not isinstance(n, int) or n < 1:
        return False

    total = 0
    number_of_digits = 0
    temp = n

    while temp > 0:
        number_of_digits += 1
        temp //= 10

    temp = n
    while temp > 0:
        rem = temp % 10
        total += rem**number_of_digits
        temp //= 10

    return n == total


def pluperfect_number(n: int) -> bool:
    if not isinstance(n, int) or n < 1:
        return False

    digit_histogram = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    digit_total = 0
    total = 0
    temp = n

    while temp > 0:
        temp, rem = divmod(temp, 10)
        digit_histogram[rem] += 1
        digit_total += 1

    for cnt, i in zip(digit_histogram, range(len(digit_histogram))):
        total += cnt * i**digit_total

    return n == total


def narcissistic_number(n: int) -> bool:
    if not isinstance(n, int) or n < 1:
        return False
    expo = len(str(n))
    return n == sum(int(i) ** expo for i in str(n))


def test_armstrong_number():
    assert all(armstrong_number(n) for n in PASSING)
    assert not any(armstrong_number(n) for n in FAILING)


def test_pluperfect_number():
    assert all(pluperfect_number(n) for n in PASSING)
    assert not any(pluperfect_number(n) for n in FAILING)


def test_narcissistic_number():
    assert all(narcissistic_number(n) for n in PASSING)
    assert not any(narcissistic_number(n) for n in FAILING)


if __name__ == "__main__":
    test_armstrong_number()
    test_pluperfect_number()
    test_narcissistic_number()