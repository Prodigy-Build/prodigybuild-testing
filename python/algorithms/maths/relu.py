import unittest
import numpy as np
from relu import relu

class ReluTestCase(unittest.TestCase):
    def test_relu(self):
        vec = np.array([-1, 0, 5])
        expected_output = np.array([0, 0, 5])
        self.assertEqual(relu(vec), expected_output)

if __name__ == '__main__':
    unittest.main()