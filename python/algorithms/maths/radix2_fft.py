```python
import unittest
from algorithms.maths.radix2_fft import FFT

class TestFFT(unittest.TestCase):
    def test_multiply(self):
        # Test case 1
        A = [0, 1, 0, 2]
        B = (2, 3, 4, 0)
        x = FFT(A, B)
        self.assertEqual(x.product, [(-0+0j), (2+0j), (3+0j), (8+0j), (6+0j), (8+0j)])

        # Test case 2
        A = [1, 2, 3]
        B = [4, 5, 6]
        x = FFT(A, B)
        self.assertEqual(x.product, [(4+0j), (13+0j), (28+0j), (27+0j), (18+0j)])

        # Test case 3
        A = [1, 2, 3, 4]
        B = [5, 6, 7, 8]
        x = FFT(A, B)
        self.assertEqual(x.product, [(5+0j), (16+0j), (34+0j), (60+0j), (70+0j), (60+0j), (32+0j)])

if __name__ == '__main__':
    unittest.main()
```