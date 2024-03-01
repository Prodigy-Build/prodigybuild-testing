def test_find_min():
    assert find_min([3, 2, 1]) == 1
    assert find_min([-3, -2, -1]) == -3
    assert find_min([3, -3, 0]) == -3
    assert find_min([3.0, 3.1, 2.9]) == 2.9
    assert find_min([0, 1, 2, 3, 4, 5, -3, 24, -56]) == -56

    try:
        find_min([])
    except ValueError as e:
        assert str(e) == "find_min() arg is an empty sequence"