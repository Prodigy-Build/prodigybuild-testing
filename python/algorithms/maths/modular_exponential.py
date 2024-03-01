def test_modular_exponential():
    assert modular_exponential(5, 0, 10) == 1
    assert modular_exponential(2, 8, 7) == 4
    assert modular_exponential(3, -2, 9) == -1