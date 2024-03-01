The updated code with unit test cases is as follows:

```python
import numpy as np
import unittest

def softmax(vector):
    exponent_vector = np.exp(vector)
    sum_of_exponents = np.sum(exponent_vector)
    softmax_vector = exponent_vector / sum_of_exponents
    return softmax_vector

class SoftmaxTestCase(unittest.TestCase):
    def test_softmax_sum_to_one(self):
        vec = [1, 2, 3, 4]
        softmax_vec = softmax(vec)
        self.assertAlmostEqual(np.sum(softmax_vec), 1.0)

    def test_softmax_equal_values(self):
        vec = [5, 5]
        softmax_vec = softmax(vec)
        self.assertAlmostEqual(softmax_vec[0], 0.5)
        self.assertAlmostEqual(softmax_vec[1], 0.5)

    def test_softmax_single_value(self):
        vec = [0]
        softmax_vec = softmax(vec)
        self.assertAlmostEqual(softmax_vec[0], 1.0)

if __name__ == "__main__":
    unittest.main()
```
