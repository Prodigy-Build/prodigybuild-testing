import unittest
class TestGaussianElimination(unittest.TestCase):

    def test_gaussian_elimination(self):
        self.assertEqual(gaussian_elimination([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]]), [[2.], [2.], [3.]])
        self.assertEqual(gaussian_elimination([[2, 2], [0, -2]], [[-1], [-1]]), [[-1.], [0.5]])

    def test_retroactive_resolution(self):
        self.assertEqual(retroactive_resolution([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]]), [[2.], [2.], [3.]])
        self.assertEqual(retroactive_resolution([[2, 2], [0, -2]], [[-1], [-1]]), [[-1.], [0.5]])

unittest.main()