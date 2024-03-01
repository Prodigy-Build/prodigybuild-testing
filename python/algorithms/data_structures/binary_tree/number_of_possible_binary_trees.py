def test_binomial_coefficient():
    assert binomial_coefficient(4, 2) == 6
    assert binomial_coefficient(5, 3) == 10
    assert binomial_coefficient(6, 4) == 15

def test_catalan_number():
    assert catalan_number(5) == 42
    assert catalan_number(6) == 132
    assert catalan_number(7) == 429

def test_factorial():
    import math
    assert all(factorial(i) == math.factorial(i) for i in range(10))
    try:
        factorial(-5)
        assert False
    except ValueError:
        assert True

def test_binary_tree_count():
    assert binary_tree_count(5) == 5040
    assert binary_tree_count(6) == 95040
    assert binary_tree_count(7) == 2079000

test_binomial_coefficient()
test_catalan_number()
test_factorial()
test_binary_tree_count()