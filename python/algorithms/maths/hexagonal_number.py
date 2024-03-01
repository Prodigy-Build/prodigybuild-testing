def test_hexagonal():
    assert hexagonal(4) == 28
    assert hexagonal(11) == 231
    assert hexagonal(22) == 946
    try:
        hexagonal(0)
        assert False, "Expected ValueError"
    except ValueError:
        pass
    try:
        hexagonal(-1)
        assert False, "Expected ValueError"
    except ValueError:
        pass
    try:
        hexagonal(11.0)
        assert False, "Expected TypeError"
    except TypeError:
        pass