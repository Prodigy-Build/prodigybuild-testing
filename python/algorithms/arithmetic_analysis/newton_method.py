import math

def test_newton():
    assert math.isclose(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3), 2.0945514815423474)
    assert math.isclose(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2), 1.0)
    assert math.isclose(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4), 1.0000000000000102)
    assert math.isclose(newton(math.sin, math.cos, 1), 0.0)
    assert math.isclose(newton(math.sin, math.cos, 2), 3.141592653589793)
    try:
        newton(math.cos, lambda x: -math.sin(x), 0)
        assert False, "ZeroDivisionError not raised"
    except ZeroDivisionError:
        pass
        
test_newton()