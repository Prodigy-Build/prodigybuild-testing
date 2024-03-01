The new code for the file "python/algorithms/maths/newton_raphson.py" is as follows:

```python
import math as m


def calc_derivative(f, a, h=0.001):
    """
    Calculates derivative at point a for function f using finite difference
    method
    """
    return (f(a + h) - f(a - h)) / (2 * h)


def newton_raphson(f, x0=0, maxiter=100, step=0.0001, maxerror=1e-6, logsteps=False):
    a = x0  # set the initial guess
    steps = [a]
    error = abs(f(a))
    f1 = lambda x: calc_derivative(f, x, h=step)  # noqa: E731  Derivative of f(x)
    for _ in range(maxiter):
        if f1(a) == 0:
            raise ValueError("No converging solution found")
        a = a - f(a) / f1(a)  # Calculate the next estimate
        if logsteps:
            steps.append(a)
        if error < maxerror:
            break
    else:
        raise ValueError("Iteration limit reached, no converging solution found")
    if logsteps:
        # If logstep is true, then log intermediate steps
        return a, error, steps
    return a, error


if __name__ == "__main__":
    from matplotlib import pyplot as plt

    f = lambda x: m.tanh(x) ** 2 - m.exp(3 * x)  # noqa: E731
    solution, error, steps = newton_raphson(
        f, x0=10, maxiter=1000, step=1e-6, logsteps=True
    )
    plt.plot([abs(f(x)) for x in steps])
    plt.xlabel("step")
    plt.ylabel("error")
    plt.show()
    print(f"solution = {{{solution:f}}}, error = {{{error:f}}}")


# Test Cases
def test_calc_derivative():
    f = lambda x: x ** 2
    assert calc_derivative(f, 2) == 4.0
    assert calc_derivative(f, 3) == 6.0
    assert calc_derivative(f, 4) == 8.0

    g = lambda x: m.sin(x)
    assert calc_derivative(g, 0) == 1.0
    assert calc_derivative(g, m.pi / 2) == 0.0
    assert calc_derivative(g, m.pi) == -1.0


def test_newton_raphson():
    f = lambda x: x ** 2 - 4
    solution, error = newton_raphson(f, x0=2, maxiter=100, step=0.0001, maxerror=1e-6)
    assert round(solution, 2) == 2.0
    assert round(error, 2) == 0.0

    g = lambda x: m.cos(x) - x
    solution, error = newton_raphson(g, x0=0.5, maxiter=100, step=0.0001, maxerror=1e-6)
    assert round(solution, 2) == 0.74
    assert round(error, 2) == 0.0


test_calc_derivative()
test_newton_raphson()
```
