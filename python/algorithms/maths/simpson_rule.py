def test_method_2():
    boundary = [0.0, 1.0]
    steps = 10.0
    result = method_2(boundary, steps)
    assert result == 0.3333333333333333

def test_make_points():
    a = 0.0
    b = 1.0
    h = 0.1
    result = list(make_points(a, b, h))
    assert result == [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]

def test_f():
    x = 0.5
    result = f(x)
    assert result == 0.25

test_method_2()
test_make_points()
test_f()