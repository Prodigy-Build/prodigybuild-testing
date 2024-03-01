```python
import unittest
from math import pi, sqrt
from random import uniform
from statistics import mean
from typing import Callable

def pi_estimator(iterations: int) -> float:
    def is_in_circle(x: float, y: float) -> bool:
        distance_from_centre = sqrt((x**2) + (y**2))
        return distance_from_centre <= 1

    proportion = mean(
        int(is_in_circle(uniform(-1.0, 1.0), uniform(-1.0, 1.0)))
        for _ in range(iterations)
    )
    pi_estimate = proportion * 4
    return pi_estimate

def area_under_curve_estimator(
    iterations: int,
    function_to_integrate: Callable[[float], float],
    min_value: float = 0.0,
    max_value: float = 1.0,
) -> float:
    return mean(
        function_to_integrate(uniform(min_value, max_value)) for _ in range(iterations)
    ) * (max_value - min_value)

def area_under_line_estimator_check(
    iterations: int, min_value: float = 0.0, max_value: float = 1.0
) -> float:
    def identity_function(x: float) -> float:
        return x

    estimated_value = area_under_curve_estimator(
        iterations, identity_function, min_value, max_value
    )
    expected_value = (max_value * max_value - min_value * min_value) / 2

    return abs(estimated_value - expected_value)

def pi_estimator_using_area_under_curve(iterations: int) -> float:
    def function_to_integrate(x: float) -> float:
        return sqrt(4.0 - x * x)

    estimated_value = area_under_curve_estimator(
        iterations, function_to_integrate, 0.0, 2.0
    )

    return abs(estimated_value - pi)

class TestMonteCarlo(unittest.TestCase):
    def test_pi_estimator(self):
        iterations = 1000000
        pi_estimate = pi_estimator(iterations)
        self.assertAlmostEqual(pi_estimate, pi, delta=0.01)

    def test_area_under_curve_estimator(self):
        iterations = 1000000
        def function_to_integrate(x: float) -> float:
            return x ** 2
        estimated_value = area_under_curve_estimator(iterations, function_to_integrate, 0.0, 1.0)
        expected_value = 1/3
        self.assertAlmostEqual(estimated_value, expected_value, delta=0.01)

    def test_area_under_line_estimator_check(self):
        iterations = 1000000
        min_value = 0.0
        max_value = 1.0
        error = area_under_line_estimator_check(iterations, min_value, max_value)
        self.assertAlmostEqual(error, 0.0, delta=0.01)

    def test_pi_estimator_using_area_under_curve(self):
        iterations = 1000000
        error = pi_estimator_using_area_under_curve(iterations)
        self.assertAlmostEqual(error, 0.0, delta=0.01)

if __name__ == "__main__":
    unittest.main()
```