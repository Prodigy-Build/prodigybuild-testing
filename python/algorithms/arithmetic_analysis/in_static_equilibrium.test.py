import pytest
from numpy.testing import assert_almost_equal


def test_polar_force():
    assert_almost_equal(polar_force(10, 45), [7.071067811865477, 7.0710678118654755])
    assert_almost_equal(polar_force(10, 3.14, radian_mode=True), [-9.999987317275396, 0.01592652916486828])


def test_in_static_equilibrium():
    forces = array([[1, 1], [-1, 2]])
    location = array([[1, 0], [10, 0]])
    assert not in_static_equilibrium(forces, location)

    forces = array([
        polar_force(718.4, 180 - 30),
        polar_force(879.54, 45),
        polar_force(100, -90),
    ])
    location = array([[0, 0], [0, 0], [0, 0]])
    assert in_static_equilibrium(forces, location)

    forces = array([
        polar_force(30 * 9.81, 15),
        polar_force(215, 180 - 45),
        polar_force(264, 90 - 30),
    ])
    location = array([[0, 0], [0, 0], [0, 0]])
    assert in_static_equilibrium(forces, location)

    forces = array([
        [0, -2000],
        [0, -1200],
        [0, 15600],
        [0, -12400]
    ])
    location = array([[0, 0], [6, 0], [10, 0], [12, 0]])
    assert in_static_equilibrium(forces, location)


test_polar_force()
test_in_static_equilibrium()