import math

class TestNewton:

    def test_newton(self):
        assert newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3) == 2.0945514815423474
        assert newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2) == 1.0
        assert newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4) == 1.0000000000000102
        assert newton(math.sin, math.cos, 1) == 0.0
        assert newton(math.sin, math.cos, 2) == 3.141592653589793
        assert newton(math.cos, lambda x: -math.sin(x), 2) == 1.5707963267948966

if __name__ == "__main__":
    import pytest
    pytest.main([__file__])