def test_factors_of_a_number():
    assert factors_of_a_number(1) == [1]
    assert factors_of_a_number(5) == [1, 5]
    assert factors_of_a_number(24) == [1, 2, 3, 4, 6, 8, 12, 24]
    assert factors_of_a_number(-24) == []

test_factors_of_a_number()