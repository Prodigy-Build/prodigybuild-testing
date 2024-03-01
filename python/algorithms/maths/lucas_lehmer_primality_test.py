def test_lucas_lehmer_test():
    assert lucas_lehmer_test(7) == True
    assert lucas_lehmer_test(11) == False