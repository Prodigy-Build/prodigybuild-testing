def test_add():
    assert add(2, 2) == 4
    assert add(2, -2) == 0
    assert add(0, 0) == 0
    assert add(0, 5) == 5
    assert add(-5, -5) == -10
    assert add(3.5, 2.5) == 6.0