import unittest
import numpy as np

def sigmoid(vector: np.array) -> np.array:
    """
    Implements the sigmoid function

    Parameters:
        vector (np.array): A  numpy array of shape (1,n)
        consisting of real values

    Returns:
        sigmoid_vec (np.array): The input numpy array, after applying
        sigmoid.

    Examples:
    >>> sigmoid(np.array([-1.0, 1.0, 2.0]))
    array([0.26894142, 0.73105858, 0.88079708])

    >>> sigmoid(np.array([0.0]))
    array([0.5])
    """
    return 1 / (1 + np.exp(-vector))

class TestSigmoid(unittest.TestCase):
    def test_sigmoid(self):
        self.assertTrue(np.allclose(sigmoid(np.array([-1.0, 1.0, 2.0])), np.array([0.26894142, 0.73105858, 0.88079708])))
        self.assertTrue(np.allclose(sigmoid(np.array([0.0])), np.array([0.5])))

if __name__ == "__main__":
    unittest.main()