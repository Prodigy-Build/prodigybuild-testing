import numpy as np


def softmax(vector):
    """
    Implements the softmax function

    Parameters:
        vector (np.array,list,tuple): A  numpy array of shape (1,n)
        consisting of real values or a similar list,tuple


    Returns:
        softmax_vec (np.array): The input numpy array  after applying
        softmax.

    The softmax vector adds up to one. We need to ceil to mitigate for
    precision
    >>> np.ceil(np.sum(softmax([1,2,3,4])))
    1.0

    >>> vec = np.array([5,5])
    >>> softmax(vec)
    array([0.5, 0.5])

    >>> softmax([0])
    array([1.])
    """

    # Calculate e^x for each x in your vector where e is Euler's
    # number (approximately 2.718)
    exponent_vector = np.exp(vector)

    # Add up the all the exponentials
    sum_of_exponents = np.sum(exponent_vector)

    # Divide every exponent by the sum of all exponents
    softmax_vector = exponent_vector / sum_of_exponents

    return softmax_vector


if __name__ == "__main__":
    print(softmax((0,)))

# Test cases

# Test case 1: vector with positive values
vec1 = np.array([1, 2, 3, 4])
assert np.ceil(np.sum(softmax(vec1))) == 1.0

# Test case 2: vector with equal values
vec2 = np.array([5, 5])
assert np.array_equal(softmax(vec2), np.array([0.5, 0.5]))

# Test case 3: vector with a single value
vec3 = np.array([0])
assert np.array_equal(softmax(vec3), np.array([1.0]))