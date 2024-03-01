def test_b_expo():
    assert b_expo(2, 3) == 8
    assert b_expo(5, 0) == 1
    assert b_expo(10, 5) == 100000
    assert b_expo(3, 4) == 81

def test_b_expo_mod():
    assert b_expo_mod(2, 3, 5) == 3
    assert b_expo_mod(5, 0, 7) == 1
    assert b_expo_mod(10, 5, 3) == 1
    assert b_expo_mod(3, 4, 2) == 1