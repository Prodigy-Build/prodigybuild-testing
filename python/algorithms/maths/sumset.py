def test_sumset():
    assert sumset({1, 2, 3}, {4, 5, 6}) == {5, 6, 7, 8, 9}
    assert sumset({1, 2, 3}, {4, 5, 6, 7}) == {5, 6, 7, 8, 9, 10}
    try:
        sumset({1, 2, 3, 4}, 3)
    except AssertionError:
        pass
    else:
        raise AssertionError("Expected AssertionError")