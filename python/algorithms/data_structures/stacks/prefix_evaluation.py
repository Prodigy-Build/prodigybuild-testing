def test_is_operand():
    assert is_operand("1") == True
    assert is_operand("+") == False

def test_evaluate():
    assert evaluate("+ 9 * 2 6") == 21
    assert evaluate("/ * 10 2 + 4 1 ") == 4.0