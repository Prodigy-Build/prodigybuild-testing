def test_two_sum():
    assert two_sum([2, 7, 11, 15], 9) == [0, 1]
    assert two_sum([15, 2, 11, 7], 13) == [1, 2]
    assert two_sum([2, 7, 11, 15], 17) == [0, 3]
    assert two_sum([7, 15, 11, 2], 18) == [0, 2]
    assert two_sum([2, 7, 11, 15], 26) == [2, 3]
    assert two_sum([2, 7, 11, 15], 8) == []
    assert two_sum([3 * i for i in range(10)], 19) == []

test_two_sum()