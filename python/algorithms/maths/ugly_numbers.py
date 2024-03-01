def test_ugly_numbers():
    assert ugly_numbers(100) == 1536
    assert ugly_numbers(0) == 1
    assert ugly_numbers(20) == 36
    assert ugly_numbers(-5) == 1
    try:
        ugly_numbers(-5.5)
    except TypeError:
        pass
    else:
        raise AssertionError("Expected TypeError")


test_ugly_numbers()