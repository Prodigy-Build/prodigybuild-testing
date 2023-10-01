```python
import unittest
import math
from typing import Tuple
from newton_method import newton

class TestNewton(unittest.TestCase):
    def test_newton(self):
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3), 2.0945514815423474)
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2), 1.0)
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4), 1.0000000000000102)
        self.assertAlmostEqual(newton(math.sin, math.cos, 1), 0.0)
        self.assertAlmostEqual(newton(math.sin, math.cos, 2), 3.141592653589793)
        self.assertAlmostEqual(newton(math.cos, lambda x: -math.sin(x), 2), 1.5707963267948966)
        
        with self.assertRaises(ZeroDivisionError):
            newton(math.cos, lambda x: -math.sin(x), 0)

if __name__ == '__main__':
    unittest.main()
```