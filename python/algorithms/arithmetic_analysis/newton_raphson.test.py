import unittest

class NewtonRaphsonTestCase(unittest.TestCase):
    def test_newton_raphson_sin_x(self):
        result = newton_raphson("sin(x)", 2)
        self.assertAlmostEqual(result, 3.1415926536808043, places=10)

    def test_newton_raphson_x_squared_minus_5x_plus_2(self):
        result = newton_raphson("x**2 - 5*x + 2", 0.4)
        self.assertAlmostEqual(result, 0.4384471871911695, places=10)

    def test_newton_raphson_x_squared_minus_5(self):
        result = newton_raphson("x**2 - 5", 0.1)
        self.assertAlmostEqual(result, 2.23606797749979, places=10)

    def test_newton_raphson_log_x_minus_1(self):
        result = newton_raphson("log(x)- 1", 2)
        self.assertAlmostEqual(result, 2.718281828458938, places=10)

if __name__ == '__main__':
    unittest.main()