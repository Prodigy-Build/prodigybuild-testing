def test_factorial():
    assert factorial(0) == 1
    assert factorial(1) == 1
    assert factorial(2) == 2
    assert factorial(3) == 6
    assert factorial(4) == 24
    assert factorial(5) == 120
    assert factorial(6) == 720
    assert factorial(10) == 362880
    assert factorial(20) == 2432902008176640000
    assert factorial(0.1) == ValueError
    assert factorial(-1) == ValueError

def test_factorial_recursive():
    assert factorial_recursive(0) == 1
    assert factorial_recursive(1) == 1
    assert factorial_recursive(2) == 2
    assert factorial_recursive(3) == 6
    assert factorial_recursive(4) == 24
    assert factorial_recursive(5) == 120
    assert factorial_recursive(6) == 720
    assert factorial_recursive(10) == 362880
    assert factorial_recursive(20) == 2432902008176640000
    assert factorial_recursive(0.1) == ValueError
    assert factorial_recursive(-1) == ValueError