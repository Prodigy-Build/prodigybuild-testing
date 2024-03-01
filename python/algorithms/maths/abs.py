def test_abs_val():
    """
    >>> test_abs_val()
    """
    assert abs_val(0) == 0
    assert abs_val(34) == 34
    assert abs_val(-100000000000) == 100000000000

    a = [-3, -1, 2, -11]
    assert abs_max(a) == -11
    assert abs_max_sort(a) == -11
    assert abs_min(a) == -1


if __name__ == "__main__":
    import doctest

    doctest.testmod()

    test_abs_val()
    print(abs_val(-34))  # --> 34