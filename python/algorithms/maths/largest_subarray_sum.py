def test_max_sub_array_sum():
    assert max_sub_array_sum([-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]) == -3
    assert max_sub_array_sum([-2, -3, 4, -1, -2, 1, 5, -3]) == 7
    assert max_sub_array_sum([1, 2, 3, 4, 5]) == 15
    assert max_sub_array_sum([-1, -2, -3, -4, -5]) == -1
    assert max_sub_array_sum([0, 0, 0, 0, 0]) == 0