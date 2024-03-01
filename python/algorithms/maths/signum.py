def test_signum() -> None:
    """
    Tests the signum function
    """
    assert signum(5) == 1
    assert signum(-5) == -1
    assert signum(0) == 0
    assert signum(12) == 1
    assert signum(-12) == -1
    assert signum(0) == 0