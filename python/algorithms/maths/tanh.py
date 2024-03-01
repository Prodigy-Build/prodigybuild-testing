import unittest
import numpy as np

def tangent_hyperbolic(vector: np.array) -> np.array:
    """
        Implements the tanh function

        Parameters:
            vector: np.array

        Returns:
            tanh (np.array): The input numpy array after applying tanh.

        mathematically (e^x - e^(-x))/(e^x + e^(-x)) can be written as (2/(1+e^(-2x))-1

    Examples:
        >>> tangent_hyperbolic(np.array([1,5,6,-0.67]))
        array([ 0.76159416,  0.9999092 ,  0.99998771, -0.58497988])

        >>> tangent_hyperbolic(np.array([8,10,2,-0.98,13]))
        array([ 0.99999977,  1.        ,  0.96402758, -0.7530659 ,  1.        ])

    """

    return (2 / (1 + np.exp(-2 * vector))) - 1


class TestTanh(unittest.TestCase):
    def test_tangent_hyperbolic(self):
        self.assertTrue(np.allclose(tangent_hyperbolic(np.array([1,5,6,-0.67])), np.array([ 0.76159416,  0.9999092 ,  0.99998771, -0.58497988])))
        self.assertTrue(np.allclose(tangent_hyperbolic(np.array([8,10,2,-0.98,13])), np.array([ 0.99999977,  1.        ,  0.96402758, -0.7530659 ,  1.        ])))

if __name__ == "__main__":
    unittest.main()