def test_neville_interpolate():
    assert neville_interpolate((1,2,3,4,6), (6,7,8,9,11), 5)[0] == 10.0
    assert neville_interpolate((1,2,3,4,6), (6,7,8,9,11), 99)[0] == 104.0
    assert neville_interpolate((1,2,3,4,6), (6,7,8,9,11), '') == TypeError

test_neville_interpolate()