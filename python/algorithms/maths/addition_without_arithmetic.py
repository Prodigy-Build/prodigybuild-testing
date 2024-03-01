def test_add():
    assert add(3, 5) == 8
    assert add(13, 5) == 18
    assert add(-7, 2) == -5
    assert add(0, -7) == -7
    assert add(-321, 0) == -321