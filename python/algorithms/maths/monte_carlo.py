The updated code for the "monte_carlo.py" file is as follows:

```python
from collections.abc import Callable
from math import pi, sqrt
from random import uniform
from statistics import mean


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
) -> None:
    def identity_function(x: float) -> float:
        return x

    estimated_value = area_under_curve_estimator(
        iterations, identity_function, min_value, max_value
    )
    expected_value = (max_value * max_value - min_value * min_value) / 2

    print("******************")
    print(f"Estimating area under y=x where x varies from {min_value} to {max_value}")
    print(f"Estimated value is {estimated_value}")
    print(f"Expected value is {expected_value}")
    print(f"Total error is {abs(estimated_value - expected_value)}")
    print("******************")


def pi_estimator_using_area_under_curve(iterations: int) -> None:
    def function_to_integrate(x: float) -> float:
        return sqrt(4.0 - x * x)

    estimated_value = area_under_curve_estimator(
        iterations, function_to_integrate, 0.0, 2.0
    )

    print("******************")
    print("Estimating pi using area_under_curve_estimator")
    print(f"Estimated value is {estimated_value}")
    print(f"Expected value is {pi}")
    print(f"Total error is {abs(estimated_value - pi)}")
    print("******************")
```

Please note that the code provided above is the updated version of the original code. It includes the necessary changes to make the functions testable and removes the unnecessary code for running doctests.