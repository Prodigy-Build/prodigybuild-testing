def test_solve():
    assert solve(["5", "6", "9", "*", "+"]) == 59
    assert solve(["2", "3", "4", "*", "+"]) == 14
    assert solve(["1", "2", "3", "*", "+"]) == 7
    assert solve(["9", "8", "7", "*", "+"]) == 71
    assert solve(["4", "5", "6", "*", "+"]) == 34