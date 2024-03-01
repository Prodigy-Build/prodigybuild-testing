def test_twin_prime():
    assert twin_prime(3) == 5
    assert twin_prime(4) == -1
    assert twin_prime(5) == 7
    assert twin_prime(17) == 19
    assert twin_prime(0) == -1
    try:
        twin_prime(6.0)
    except TypeError as e:
        assert str(e) == "Input value of [number=6.0] must be an integer"