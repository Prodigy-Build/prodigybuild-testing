def test_method_2():
    boundary = [0.0, 1.0]
    steps = 10.0
    result = method_2(boundary, steps)
    assert result == 0.3333333333333333

    boundary = [0.0, 2.0]
    steps = 20.0
    result = method_2(boundary, steps)
    assert result == 2.6666666666666665

    boundary = [0.0, 3.0]
    steps = 30.0
    result = method_2(boundary, steps)
    assert result == 6.0

    boundary = [0.0, 4.0]
    steps = 40.0
    result = method_2(boundary, steps)
    assert result == 10.666666666666666

    boundary = [0.0, 5.0]
    steps = 50.0
    result = method_2(boundary, steps)
    assert result == 16.0

    boundary = [0.0, 6.0]
    steps = 60.0
    result = method_2(boundary, steps)
    assert result == 22.666666666666668

    boundary = [0.0, 7.0]
    steps = 70.0
    result = method_2(boundary, steps)
    assert result == 30.0

    boundary = [0.0, 8.0]
    steps = 80.0
    result = method_2(boundary, steps)
    assert result == 38.666666666666664

    boundary = [0.0, 9.0]
    steps = 90.0
    result = method_2(boundary, steps)
    assert result == 48.0

    boundary = [0.0, 10.0]
    steps = 100.0
    result = method_2(boundary, steps)
    assert result == 58.666666666666664