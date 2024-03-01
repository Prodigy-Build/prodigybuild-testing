def test_find_max():
    assert find_max([3, 2, 1]) == 3
    assert find_max([-3, -2, -1]) == -1
    assert find_max([3, -3, 0]) == 3
    assert find_max([3.0, 3.1, 2.9]) == 3.1
    assert find_max([2, 4, 9, 7, 19, 94, 5]) == 94

    try:
        find_max([])
    except ValueError as e:
        assert str(e) == "find_max() arg is an empty sequence"
    else:
        raise AssertionError("Expected ValueError")