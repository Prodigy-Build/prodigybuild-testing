def test_sum_of_digits():
    assert sum_of_digits(12345) == 15
    assert sum_of_digits(123) == 6
    assert sum_of_digits(-123) == 6
    assert sum_of_digits(0) == 0


def test_sum_of_digits_recursion():
    assert sum_of_digits_recursion(12345) == 15
    assert sum_of_digits_recursion(123) == 6
    assert sum_of_digits_recursion(-123) == 6
    assert sum_of_digits_recursion(0) == 0


def test_sum_of_digits_compact():
    assert sum_of_digits_compact(12345) == 15
    assert sum_of_digits_compact(123) == 6
    assert sum_of_digits_compact(-123) == 6
    assert sum_of_digits_compact(0) == 0