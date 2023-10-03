from sympy import diff, lambdify, symbols
from sympy.functions import * 

def test_newton_raphson():
    assert newton_raphson("sin(x)", 2) == 3.141592653589793
    assert newton_raphson("x**4 -5", 0.4 + 5j) == (-7.52316384526264e-37+1.4953487812212207j)
    assert newton_raphson('log(y) - 1', 2, variable='y') == 2.7182818284590455
    assert newton_raphson('exp(x) - 1', 10, precision=0.005) == 1.2186556186174883e-10
    try:
        newton_raphson('cos(x)', 0)
    except ZeroDivisionError:
        pass
    else:
        raise AssertionError("ZeroDivisionError not raised")
        
test_newton_raphson()