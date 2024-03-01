def test_floor():
    assert floor(1) == 1
    assert floor(-1) == -1
    assert floor(0) == 0
    assert floor(-0) == -0
    assert floor(1.1) == 1
    assert floor(-1.1) == -2
    assert floor(1.0) == 1
    assert floor(-1.0) == -1
    assert floor(1_000_000_000) == 1_000_000_000

test_floor()