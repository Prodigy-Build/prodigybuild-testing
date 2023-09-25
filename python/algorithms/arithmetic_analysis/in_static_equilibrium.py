import unittest
from numpy.testing import assert_almost_equal

class TestEquilibrium(unittest.TestCase):
    def test_polar_force(self):
        assert_almost_equal(polar_force(10, 45), [7.071067811865477, 7.0710678118654755])
        assert_almost_equal(polar_force(10, 3.14, radian_mode=True), [-9.999987317275396, 0.01592652916486828])

    def test_in_static_equilibrium(self):
        forces = array([[1, 1], [-1, 2]])
        location = array([[1, 0], [10, 0]])
        self.assertFalse(in_static_equilibrium(forces, location))

if __name__ == '__main__':
    unittest.main()