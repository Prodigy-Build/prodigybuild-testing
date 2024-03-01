def test_manhattan_distance():
    assert manhattan_distance([1,1], [2,2]) == 2.0
    assert manhattan_distance([1.5,1.5], [2,2]) == 1.0
    assert manhattan_distance([1.5,1.5], [2.5,2]) == 1.5
    assert manhattan_distance([-3, -3, -3], [0, 0, 0]) == 9.0
    try:
        manhattan_distance([1,1], None)
    except ValueError as e:
        assert str(e) == "Missing an input"
    try:
        manhattan_distance([1,1], [2, 2, 2])
    except ValueError as e:
        assert str(e) == "Both points must be in the same n-dimensional space"
    try:
        manhattan_distance([1,"one"], [2, 2, 2])
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found str"
    try:
        manhattan_distance(1, [2, 2, 2])
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found int"
    try:
        manhattan_distance([1,1], "not_a_list")
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found str"

def test_manhattan_distance_one_liner():
    assert manhattan_distance_one_liner([1,1], [2,2]) == 2.0
    assert manhattan_distance_one_liner([1.5,1.5], [2,2]) == 1.0
    assert manhattan_distance_one_liner([1.5,1.5], [2.5,2]) == 1.5
    assert manhattan_distance_one_liner([-3, -3, -3], [0, 0, 0]) == 9.0
    try:
        manhattan_distance_one_liner([1,1], None)
    except ValueError as e:
        assert str(e) == "Missing an input"
    try:
        manhattan_distance_one_liner([1,1], [2, 2, 2])
    except ValueError as e:
        assert str(e) == "Both points must be in the same n-dimensional space"
    try:
        manhattan_distance_one_liner([1,"one"], [2, 2, 2])
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found str"
    try:
        manhattan_distance_one_liner(1, [2, 2, 2])
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found int"
    try:
        manhattan_distance_one_liner([1,1], "not_a_list")
    except TypeError as e:
        assert str(e) == "Expected a list of numbers as input, found str"