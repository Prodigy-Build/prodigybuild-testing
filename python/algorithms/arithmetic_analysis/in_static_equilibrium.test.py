import pytest

def test_polar_force():
    assert math.isclose(polar_force(10, 45)[0], 7.071067811865477)
    assert math.isclose(polar_force(10, 45)[1], 7.0710678118654755)
    assert math.isclose(polar_force(10, 3.14, radian_mode=True)[0], -9.999987317275396)
    assert math.isclose(polar_force(10, 3.14, radian_mode=True)[1], 0.01592652916486828)

def test_in_static_equilibrium():
    forces = array([[1, 1], [-1, 2]])
    location = array([[1, 0], [10, 0]])
    assert in_static_equilibrium(forces, location) == False

    forces = array([
        polar_force(30 * 9.81, 15),
        polar_force(215, 180 - 45),
        polar_force(264, 90 - 30),
    ])
    location = array([[0, 0], [0, 0], [0, 0]])
    assert in_static_equilibrium(forces, location) == True

    forces = array([[0, -2000], [0, -1200], [0, 15600], [0, -12400]])
    location = array([[0, 0], [6, 0], [10, 0], [12, 0]])
    assert in_static_equilibrium(forces, location) == True

pytest.main(['-v', '--doctest-modules'])