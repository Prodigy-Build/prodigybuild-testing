def test_add():
    assert add(2, 2) == 4
    assert add(2, -2) == 0
    assert add(0, 0) == 0
    assert add(0, 5) == 5
    assert add(-5, -5) == -10
    assert add(3.5, 2.5) == 6.0
    assert add(-3.5, 2.5) == -1.0
    assert add(10, -10) == 0
    assert add(1000000, 1) == 1000001
    assert add(1, 1000000) == 1000001

test_add()