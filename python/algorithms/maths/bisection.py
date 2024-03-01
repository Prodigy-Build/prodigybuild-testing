def test_equation():
    assert equation(5) == -15
    assert equation(0) == 10
    assert equation(-5) == -15
    assert equation(0.1) == 9.99
    assert equation(-0.1) == 9.99


def test_bisection():
    assert bisection(-2, 5) == 3.1611328125
    assert bisection(0, 6) == 3.158203125
    try:
        bisection(2, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "Wrong space!"


test_equation()
test_bisection()