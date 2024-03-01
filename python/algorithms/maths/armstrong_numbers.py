from typing import Tuple

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


def test_armstrong_number() -> None:
    passing_numbers = (1, 153, 370, 371, 1634, 24678051, 115132219018763992565095597973971522401)
    failing_numbers = (-153, -1, 0, 1.2, 200, "A", [], {}, None)

    for num in passing_numbers:
        assert armstrong_number(num) is True

    for num in failing_numbers:
        assert armstrong_number(num) is False


def test_pluperfect_number() -> None:
    passing_numbers = (1, 153, 370, 371, 1634, 24678051, 115132219018763992565095597973971522401)
    failing_numbers = (-153, -1, 0, 1.2, 200, "A", [], {}, None)

    for num in passing_numbers:
        assert pluperfect_number(num) is True

    for num in failing_numbers:
        assert pluperfect_number(num) is False


def test_narcissistic_number() -> None:
    passing_numbers = (1, 153, 370, 371, 1634, 24678051, 115132219018763992565095597973971522401)
    failing_numbers = (-153, -1, 0, 1.2, 200, "A", [], {}, None)

    for num in passing_numbers:
        assert narcissistic_number(num) is True

    for num in failing_numbers:
        assert narcissistic_number(num) is False


if __name__ == "__main__":
    test_armstrong_number()
    test_pluperfect_number()
    test_narcissistic_number()