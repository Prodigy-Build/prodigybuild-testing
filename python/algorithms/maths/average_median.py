def test_median():
    assert median([0]) == 0
    assert median([4, 1, 3, 2]) == 2.5
    assert median([2, 70, 6, 50, 20, 8, 4]) == 8