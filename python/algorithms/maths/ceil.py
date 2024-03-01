from math import ceil

def test_ceil():
    assert ceil(1) == 1
    assert ceil(-1) == -1
    assert ceil(0) == 0
    assert ceil(-0) == 0
    assert ceil(1.1) == 2
    assert ceil(-1.1) == -1
    assert ceil(1.0) == 1
    assert ceil(-1.0) == -1
    assert ceil(1_000_000_000) == 1_000_000_000

test_ceil()