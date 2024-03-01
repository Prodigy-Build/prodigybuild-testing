import unittest
import numpy as np

def sigmoid(vector: np.array) -> np.array:
    return 1 / (1 + np.exp(-vector))

def gaussian_error_linear_unit(vector: np.array) -> np.array:
    return vector * sigmoid(1.702 * vector)

class TestGaussianErrorLinearUnit(unittest.TestCase):
    def test_gaussian_error_linear_unit(self):
        self.assertTrue(np.allclose(gaussian_error_linear_unit(np.array([-1.0, 1.0, 2.0])), np.array([-0.15420423,  0.84579577,  1.93565862])))
        self.assertTrue(np.allclose(gaussian_error_linear_unit(np.array([-3])), np.array([-0.01807131])))

if __name__ == "__main__":
    unittest.main()