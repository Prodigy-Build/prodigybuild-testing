from decimal import Decimal
# write unit tests
def test_newton_raphson():
    assert newton_raphson("sin(x)", 2) == 3.1415926536808043
    assert newton_raphson("x**2 - 5*x +2", 0.4) == 0.4384471871911695
    assert newton_raphson("x**2 - 5", 0.1) == 2.23606797749979
    assert newton_raphson("log(x)- 1", 2) == 2.718281828458938

test_newton_raphson()