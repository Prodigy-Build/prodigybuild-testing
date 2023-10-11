def test_newton():
    assert abs(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3) - 2.0945514815423474) < 10**-5
    assert abs(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2) - 1.0) < 10**-5
    assert abs(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4) - 1.0000000000000102) < 10**-5
    import math
    assert abs(newton(math.sin, math.cos, 1) - 0.0) < 10**-5
    assert abs(newton(math.sin, math.cos, 2) - 3.141592653589793) < 10**-5
    assert abs(newton(math.cos, lambda x: -math.sin(x), 2) - 1.5707963267948966) < 10**-5
    
test_newton()