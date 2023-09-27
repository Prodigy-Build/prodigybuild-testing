from typing import List

def test_polar_force():
    assert polar_force(10, 45) == [7.071067811865477, 7.0710678118654755]
    assert polar_force(10, 3.14, radian_mode=True) == [-9.999987317275396, 0.01592652916486828]

def test_in_static_equilibrium():
    force = [[1, 1], [-1, 2]]
    location = [[1, 0], [10, 0]]
    assert in_static_equilibrium(force, location) == False

test_polar_force()
test_in_static_equilibrium()