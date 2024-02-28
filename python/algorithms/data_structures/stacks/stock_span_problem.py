def test_calculation_span():
    price = [10, 4, 5, 90, 120, 80]
    S = [0 for i in range(len(price) + 1)]
    calculation_span(price, S)
    assert S == [1, 1, 2, 4, 5, 1]