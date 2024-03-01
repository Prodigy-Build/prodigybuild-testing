import unittest
import numpy as np

class TestSigmoid(unittest.TestCase):
    def test_sigmoid(self):
        self.assertTrue(np.allclose(sigmoid(np.array([-1.0, 1.0, 2.0])), np.array([0.26894142, 0.73105858, 0.88079708])))

class TestSigmoidLinearUnit(unittest.TestCase):
    def test_sigmoid_linear_unit(self):
        self.assertTrue(np.allclose(sigmoid_linear_unit(np.array([-1.0, 1.0, 2.0])), np.array([-0.26894142, 0.73105858, 1.76159416])))
        self.assertTrue(np.allclose(sigmoid_linear_unit(np.array([-2])), np.array([-0.23840584])))

if __name__ == "__main__":
    unittest.main()