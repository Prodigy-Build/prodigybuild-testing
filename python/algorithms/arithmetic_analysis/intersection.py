The code provided is already compliant with the latest Python version (Python 3). Thus, no changes are necessary. But you might want to consider adding type hints for better documentation and usability. The updated code could look like this:

```python
from typing import Callable
import math


def intersection(function: Callable[[float], float], x0: float, x1: float) -> float:
    """
    function is the f we want to find its root
    x0 and x1 are two random starting points
    """
    x_n: float = x0
    x_n1: float = x1
    while True:
        if x_n == x_n1 or function(x_n1) == function(x_n):
            raise ZeroDivisionError("float division by zero, could not find root")
        x_n2: float = x_n1 - ( function(x_n1) / ((function(x_n1) - function(x_n)) / (x_n1 - x_n)) )
        if abs(x_n2 - x_n1) < 10**-5:
            return x_n2
        x_n = x_n1
        x_n1 = x_n2


def f(x: float) -> float:
    return math.pow(x, 3) - (2 * x) - 5


if __name__ == "__main__":
    print(intersection(f, 3, 3.5))
```
This code should run without any issues in the latest Python version. Please remember to import any additional modules required by your function.