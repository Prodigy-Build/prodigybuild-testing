def test_catalan():
    assert catalan(5) == 14
    try:
        catalan(0)
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")
    try:
        catalan(-1)
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")
    try:
        catalan(5.0)
    except TypeError:
        pass
    else:
        raise AssertionError("Expected TypeError")