import unittest
from unittest.mock import patch
from algorithms.maths.radix2_fft import FFT


class TestFFT(unittest.TestCase):
    def test_init(self):
        poly_a = [0, 1, 0, 2]
        poly_b = (2, 3, 4, 0)
        fft = FFT(poly_a, poly_b)
        self.assertEqual(fft.polyA, poly_a)
        self.assertEqual(fft.polyB, poly_b)
        self.assertEqual(fft.len_A, 3)
        self.assertEqual(fft.len_B, 3)
        self.assertEqual(fft.c_max_length, 8)
        self.assertEqual(fft.root, complex(1, 0))
        self.assertEqual(fft.product, [0, 2, 3, 8, 6, 8])

    def test_init_with_none(self):
        fft = FFT()
        self.assertEqual(fft.polyA, [0])
        self.assertEqual(fft.polyB, [0])
        self.assertEqual(fft.len_A, 0)
        self.assertEqual(fft.len_B, 0)
        self.assertEqual(fft.c_max_length, 1)
        self.assertEqual(fft.root, complex(1, 0))
        self.assertEqual(fft.product, [0])

    def test_dft(self):
        poly_a = [0, 1, 0, 2]
        poly_b = (2, 3, 4, 0)
        fft = FFT(poly_a, poly_b)
        dft_a = fft._FFT__dft("A")
        dft_b = fft._FFT__dft("B")
        self.assertEqual(dft_a, [0, 1, 0, 2, 0, 0, 0, 0])
        self.assertEqual(dft_b, [2, 3, 4, 0, 0, 0, 0, 0])

    def test_multiply(self):
        poly_a = [0, 1, 0, 2]
        poly_b = (2, 3, 4, 0)
        fft = FFT(poly_a, poly_b)
        product = fft._FFT__multiply()
        self.assertEqual(product, [0, 2, 3, 8, 6, 8])

    def test_str(self):
        poly_a = [0, 1, 0, 2]
        poly_b = (2, 3, 4, 0)
        fft = FFT(poly_a, poly_b)
        expected_str = "A = 0*x^0 + 1*x^1 + 2*x^0 + 3*x^2\nB = 0*x^2 + 1*x^3 + 2*x^4\nA*B = 0*x^0 + 2*x^1 + 3*x^2 + 8*x^3 + 6*x^4 + 8*x^5"
        self.assertEqual(str(fft), expected_str)


if __name__ == "__main__":
    unittest.main()