def test_factorial():
    assert factorial(0) == 1
    assert factorial(1) == 1
    assert factorial(2) == 2
    assert factorial(3) == 6
    assert factorial(4) == 24
    assert factorial(5) == 120
    assert factorial(6) == 720
    assert factorial(10) == 362880
    assert factorial(20) == 2432902008176640000

    try:
        factorial(0.1)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial(-1)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial("abc")
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial(None)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial([])
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial({})
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial(-10)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial(10.5)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        factorial(1000000)
        assert False, "Expected RecursionError"
    except RecursionError:
        pass