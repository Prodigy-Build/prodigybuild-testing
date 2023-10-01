import unittest
# ADD UNIT TESTS HERE

class InStaticEquilibriumTest(unittest.TestCase):
    def test_polar_force(self):
        force = polar_force(10, 45)
        self.assertAlmostEqual(force[0], 7.071067811865477)
        self.assertAlmostEqual(force[1], 7.0710678118654755)

        force = polar_force(10, 3.14, radian_mode=True)
        self.assertAlmostEqual(force[0], -9.999987317275396)
        self.assertAlmostEqual(force[1], 0.01592652916486828)

    def test_in_static_equilibrium(self):
        force = array([[1, 1], [-1, 2]])
        location = array([[1, 0], [10, 0]])
        self.assertFalse(in_static_equilibrium(force, location))

        forces = array(
            [
                polar_force(718.4, 180 - 30),
                polar_force(879.54, 45),
                polar_force(100, -90),
            ]
        )

        location = array([[0, 0], [0, 0], [0, 0]])

        self.assertTrue(in_static_equilibrium(forces, location))

        forces = array(
            [
                polar_force(30 * 9.81, 15),
                polar_force(215, 180 - 45),
                polar_force(264, 90 - 30),
            ]
        )

        location = array([[0, 0], [0, 0], [0, 0]])

        self.assertTrue(in_static_equilibrium(forces, location))

        forces = array([[0, -2000], [0, -1200], [0, 15600], [0, -12400]])

        location = array([[0, 0], [6, 0], [10, 0], [12, 0]])

        self.assertTrue(in_static_equilibrium(forces, location))


suite = unittest.TestLoader().loadTestsFromTestCase(InStaticEquilibriumTest)
runner = unittest.TextTestRunner(verbosity=2)
runner.run(suite)