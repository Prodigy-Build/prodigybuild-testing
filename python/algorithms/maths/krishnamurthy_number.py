def test_factorial():
    assert factorial(3) == 6
    assert factorial(0) == 1
    assert factorial(5) == 120


def test_krishnamurthy():
    assert krishnamurthy(145) == True
    assert krishnamurthy(240) == False
    assert krishnamurthy(1) == True