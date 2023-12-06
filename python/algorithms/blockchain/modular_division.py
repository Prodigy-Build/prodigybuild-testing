def test_modular_division():
    assert modular_division(4, 8, 5) == 2
    assert modular_division(3, 8, 5) == 1
    assert modular_division(4, 11, 5) == 4

def test_invert_modulo():
    assert invert_modulo(2, 5) == 3
    assert invert_modulo(8, 7) == 1

test_modular_division()
test_invert_modulo()