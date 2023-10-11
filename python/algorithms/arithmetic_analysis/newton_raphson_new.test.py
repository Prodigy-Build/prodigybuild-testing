import unittest
from newton_raphson_new import newton_raphson

class NewtonRaphsonTest(unittest.TestCase):
    def test_sin_function(self):
        actual_result = newton_raphson("sin(x)", 2)
        expected_result = 3.141592653589793
        self.assertAlmostEqual(actual_result, expected_result)
    
    def test_polynomial_function(self):
        actual_result = newton_raphson("x**4 -5", 0.4 + 5j)
        expected_result = (-7.52316384526264e-37+1.4953487812212207j)
        self.assertAlmostEqual(actual_result, expected_result)
    
    def test_log_function(self):
        actual_result = newton_raphson("log(y) - 1", 2, variable='y')
        expected_result = 2.7182818284590455
        self.assertAlmostEqual(actual_result, expected_result)
    
    def test_exponential_function(self):
        actual_result = newton_raphson("exp(x) - 1", 10, precision=0.005)
        expected_result = 1.2186556186174883e-10
        self.assertAlmostEqual(actual_result, expected_result)
    
    def test_cos_function(self):
        with self.assertRaises(ZeroDivisionError):
            newton_raphson("cos(x)", 0)

if __name__ == "__main__":
    unittest.main()