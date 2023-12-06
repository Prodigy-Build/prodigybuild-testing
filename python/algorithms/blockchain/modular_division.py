def test_modular_division():
    assert modular_division(4, 8, 5) == 2
    assert modular_division(3, 8, 5) == 1
    assert modular_division(4, 11, 5) == 4

def test_invert_modulo():
    assert invert_modulo(2, 5) == 3
    assert invert_modulo(8, 7) == 1

def test_modular_division2():
    assert modular_division2(4, 8, 5) == 2
    assert modular_division2(3, 8, 5) == 1
    assert modular_division2(4, 11, 5) == 4

def test_extended_gcd():
    assert extended_gcd(10, 6) == (2, -1, 2)
    assert extended_gcd(7, 5) == (1, -2, 3)

def test_extended_euclid():
    assert extended_euclid(10, 6) == (-1, 2)
    assert extended_euclid(7, 5) == (-2, 3)

def test_greatest_common_divisor():
    assert greatest_common_divisor(7, 5) == 1
    assert greatest_common_divisor(121, 11) == 11