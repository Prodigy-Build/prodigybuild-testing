```python
import unittest
from numpy import array
from gaussian_elimination import gaussian_elimination, retroactive_resolution

class TestGaussianElimination(unittest.TestCase):
    
    def test_gaussian_elimination(self):
        # Test case 1
        coefficients = array([[2, 2, -1], [0, -2, -1], [0, 0, 5]])
        vector = array([[5], [-7], [15]])
        result = gaussian_elimination(coefficients, vector)
        expected = array([[2.], [2.], [3.]])
        self.assertTrue((result == expected).all())
        
        # Test case 2
        coefficients = array([[2, 2], [0, -2]])
        vector = array([[-1], [-1]])
        result = gaussian_elimination(coefficients, vector)
        expected = array([[-1.], [0.5]])
        self.assertTrue((result == expected).all())
    
    def test_retroactive_resolution(self):
        # Test case 1
        coefficients = array([[2, 2, -1], [0, -2, -1], [0, 0, 5]])
        vector = array([[5], [-7], [15]])
        result = retroactive_resolution(coefficients, vector)
        expected = array([[2.], [2.], [3.]])
        self.assertTrue((result == expected).all())
        
        # Test case 2
        coefficients = array([[2, 2], [0, -2]])
        vector = array([[-1], [-1]])
        result = retroactive_resolution(coefficients, vector)
        expected = array([[-1.], [0.5]])
        self.assertTrue((result == expected).all())

if __name__ == '__main__':
    unittest.main()
```