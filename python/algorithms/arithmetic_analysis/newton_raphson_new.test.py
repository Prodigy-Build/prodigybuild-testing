import unittest

class TestNewtonRaphson(unittest.TestCase):
    def test_sin_function(self):
        result = newton_raphson("sin(x)", 2)
        self.assertAlmostEqual(result, 3.141592653589793)
    
    def test_polynomial_function(self):
        result = newton_raphson("x**4 - 5", 0.4 + 5j)
        self.assertAlmostEqual(result, (-7.52316384526264e-37 + 1.4953487812212207j))

    def test_log_function(self):
        result = newton_raphson("log(y) - 1", 2, variable="y")
        self.assertAlmostEqual(result, 2.7182818284590455)

    def test_exponential_function(self):
        result = newton_raphson("exp(x) - 1", 10, precision=0.005)
        self.assertAlmostEqual(result, 1.2186556186174883e-10)

    def test_cos_function(self):
        with self.assertRaises(ZeroDivisionError):
            newton_raphson("cos(x)", 0)

if __name__ == "__main__":
    unittest.main()