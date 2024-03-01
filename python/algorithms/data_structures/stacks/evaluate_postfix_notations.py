def test_evaluate_postfix():
    assert evaluate_postfix(["2", "1", "+", "3", "*"]) == 9
    assert evaluate_postfix(["4", "13", "5", "/", "+"]) == 6
    assert evaluate_postfix([]) == 0
    assert evaluate_postfix(["10", "5", "*", "2", "/"]) == 10
    assert evaluate_postfix(["3", "4", "+", "5", "*", "2", "-"]) == 17
    assert evaluate_postfix(["1", "2", "+", "3", "4", "*", "+"]) == 15
    assert evaluate_postfix(["5", "1", "2", "+", "4", "*", "+", "3", "-"]) == 14
    assert evaluate_postfix(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]) == 22

test_evaluate_postfix()