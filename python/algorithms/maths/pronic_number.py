def test_is_pronic():
    assert is_pronic(-1) == False
    assert is_pronic(0) == True
    assert is_pronic(2) == True
    assert is_pronic(5) == False
    assert is_pronic(6) == True
    assert is_pronic(8) == False
    assert is_pronic(30) == True
    assert is_pronic(32) == False
    assert is_pronic(2147441940) == True
    assert is_pronic(9223372033963249500) == True
    try:
        is_pronic(6.0)
    except TypeError:
        pass
    else:
        raise AssertionError("Expected TypeError")