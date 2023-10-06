import unittest

class NewtonRaphsonTestCase(unittest.TestCase):
    def test_sin_x(self):
        self.assertAlmostEqual(newton_raphson("sin(x)", 2), 3.141592653589793)

    def test_polynomial(self):
        self.assertAlmostEqual(newton_raphson("x**4 - 5", 0.4 + 5j), (-7.52316384526264e-37+1.4953487812212207j))
    
    def test_log_y(self):
        self.assertAlmostEqual(newton_raphson('log(y) - 1', 2, variable='y'), 2.7182818284590455)

    def test_exp(self):
        self.assertAlmostEqual(newton_raphson('exp(x) - 1', 10, precision=0.005), 1.2186556186174883e-10)

    def test_cos_x(self):
        with self.assertRaises(ZeroDivisionError):
            newton_raphson('cos(x)', 0)

unittest.main()