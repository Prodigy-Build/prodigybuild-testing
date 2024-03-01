import numpy as np


def sigmoid(vector: np.array) -> np.array:
    """
    Mathematical function sigmoid takes a vector x of K real numbers as input and
    returns 1/ (1 + e^-x).
    https://en.wikipedia.org/wiki/Sigmoid_function

    >>> sigmoid(np.array([-1.0, 1.0, 2.0]))
    array([0.26894142, 0.73105858, 0.88079708])
    """
    return 1 / (1 + np.exp(-vector))


def gaussian_error_linear_unit(vector: np.array) -> np.array:
    """
    Implements the Gaussian Error Linear Unit (GELU) function

    Parameters:
        vector (np.array): A  numpy array of shape (1,n)
        consisting of real values

    Returns:
        gelu_vec (np.array): The input numpy array, after applying
        gelu.

    Examples:
    >>> gaussian_error_linear_unit(np.array([-1.0, 1.0, 2.0]))
    array([-0.15420423,  0.84579577,  1.93565862])

    >>> gaussian_error_linear_unit(np.array([-3]))
    array([-0.01807131])
    """
    return vector * sigmoid(1.702 * vector)


if __name__ == "__main__":
    import doctest

    doctest.testmod()

# Additional test cases
def test_sigmoid():
    assert np.allclose(sigmoid(np.array([-1.0, 1.0, 2.0])), np.array([0.26894142, 0.73105858, 0.88079708]))
    assert np.allclose(sigmoid(np.array([0])), np.array([0.5]))

def test_gaussian_error_linear_unit():
    assert np.allclose(gaussian_error_linear_unit(np.array([-1.0, 1.0, 2.0])), np.array([-0.15420423,  0.84579577,  1.93565862]))
    assert np.allclose(gaussian_error_linear_unit(np.array([-3])), np.array([-0.01807131]))

test_sigmoid()
test_gaussian_error_linear_unit()