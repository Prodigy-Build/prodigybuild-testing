import unittest
from math import isclose, sin, radians


class SinTestCase(unittest.TestCase):
    def test_sin_zero(self):
        self.assertTrue(isclose(sin(0.0), 0.0, abs_tol=1e-10))

    def test_sin_ninety(self):
        self.assertTrue(isclose(sin(90.0), 1.0, abs_tol=1e-10))

    def test_sin_one_eighty(self):
        self.assertTrue(isclose(sin(180.0), 0.0, abs_tol=1e-10))

    def test_sin_two_seventy(self):
        self.assertTrue(isclose(sin(270.0), -1.0, abs_tol=1e-10))

    def test_sin_point_six_eight(self):
        self.assertTrue(isclose(sin(0.68), 0.0118679603, abs_tol=1e-10))

    def test_sin_one_ninety_seven(self):
        self.assertTrue(isclose(sin(1.97), 0.0343762121, abs_tol=1e-10))

    def test_sin_sixty_four(self):
        self.assertTrue(isclose(sin(64.0), 0.8987940463, abs_tol=1e-10))

    def test_sin_nine_thousand_nine_hundred_ninety_nine(self):
        self.assertTrue(isclose(sin(9999.0), -0.9876883406, abs_tol=1e-10))

    def test_sin_negative_six_hundred_eighty_nine(self):
        self.assertTrue(isclose(sin(-689.0), 0.5150380749, abs_tol=1e-10))

    def test_sin_eighty_nine_point_seven(self):
        self.assertTrue(isclose(sin(89.7), 0.9999862922, abs_tol=1e-10))


if __name__ == "__main__":
    unittest.main()