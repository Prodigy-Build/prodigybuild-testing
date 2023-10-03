import pytest

def test_polar_force():
    force = polar_force(10, 45)
    assert math.isclose(force[0], 7.071067811865477)
    assert math.isclose(force[1], 7.0710678118654755)

    force = polar_force(10, 3.14, radian_mode=True)
    assert math.isclose(force[0], -9.999987317275396)
    assert math.isclose(force[1], 0.01592652916486828)

def test_in_static_equilibrium():
    forces = array([[1, 1], [-1, 2]])
    location = array([[1, 0], [10, 0]])
    assert not in_static_equilibrium(forces, location)

    forces = array([[0, -2000], [0, -1200], [0, 15600], [0, -12400]])
    location = array([[0, 0], [6, 0], [10, 0], [12, 0]])
    assert in_static_equilibrium(forces, location)