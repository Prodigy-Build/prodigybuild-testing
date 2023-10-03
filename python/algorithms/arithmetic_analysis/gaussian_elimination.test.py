import unittest
class TestGaussianElimination(unittest.TestCase):

    def test_gaussian_elimination(self):
        self.assertAlmostEqual(gaussian_elimination([[2, 2, -1], [0, -2, -1], [0, 0, 5]], [[5], [-7], [15]]),np.array([[2.],[2.],[3.]]))
        
        self.assertAlmostEqual(gaussian_elimination([[2, 2], [0, -2]], [[-1], [-1]]),np.array([[-1. ],[ 0.5]]))
        
unittest.main()