def test_sumset():
    assert sumset({1, 2, 3}, {4, 5, 6}) == {5, 6, 7, 8, 9}
    assert sumset({1, 2, 3}, {4, 5, 6, 7}) == {5, 6, 7, 8, 9, 10}
    assert sumset({1, 2, 3, 4}, 3) == AssertionError

test_sumset()