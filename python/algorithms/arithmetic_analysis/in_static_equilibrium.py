import unittest

class TestInStaticEquilibrium(unittest.TestCase):

    def test_polar_force(self):
        self.assertAlmostEqual(polar_force(10, 45)[0], 7.071067811865477)
        self.assertAlmostEqual(polar_force(10, 45)[1], 7.0710678118654755)
        self.assertAlmostEqual(polar_force(10, 3.14, radian_mode=True)[0], -9.999987317275396)
        self.assertAlmostEqual(polar_force(10, 3.14, radian_mode=True)[1], 0.01592652916486828)

    def test_in_static_equilibrium(self):
        self.assertFalse(in_static_equilibrium(array([[1, 1], [-1, 2]]), array([[1, 0], [10, 0]])))

if __name__ == "__main__":
    unittest.main()