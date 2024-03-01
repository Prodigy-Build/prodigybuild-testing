def test_power():
    assert power(3, 4) == 81
    assert power(2, 0) == 1
    assert all(power(base, exponent) == pow(base, exponent)
               for base in range(-10, 10) for exponent in range(10))

test_power()