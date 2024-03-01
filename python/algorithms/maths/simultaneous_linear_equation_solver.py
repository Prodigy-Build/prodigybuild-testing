def test_simplify():
    assert simplify([[1, 2, 3], [4, 5, 6]]) == [[1.0, 2.0, 3.0], [0.0, 0.75, 1.5]]
    assert simplify([[5, 2, 5], [5, 1, 10]]) == [[1.0, 0.4, 1.0], [0.0, 0.2, -1.0]]


def test_solve_simultaneous():
    assert solve_simultaneous([[1, 2, 3], [4, 5, 6]]) == [-1.0, 2.0]
    assert solve_simultaneous([[0, -3, 1, 7], [3, 2, -1, 11], [5, 1, -2, 12]]) == [6.4, 1.2, 10.6]
    try:
        solve_simultaneous([])
    except IndexError:
        pass
    else:
        assert False, "Expected IndexError"
    try:
        solve_simultaneous([[1, 2, 3], [1, 2]])
    except IndexError:
        pass
    else:
        assert False, "Expected IndexError"
    try:
        solve_simultaneous([[1, 2, 3], ["a", 7, 8]])
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError"
    try:
        solve_simultaneous([[0, 2, 3], [4, 0, 6]])
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError"


test_simplify()
test_solve_simultaneous()