def test_evaluate_postfix():
    assert evaluate_postfix(["2", "1", "+", "3", "*"]) == 9
    assert evaluate_postfix(["4", "13", "5", "/", "+"]) == 6
    assert evaluate_postfix([]) == 0