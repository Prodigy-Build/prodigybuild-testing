# New code

def test_sylvester():
    assert sylvester(8) == 113423713055421844361000443

    try:
        sylvester(-1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "The input value of [n=-1] has to be > 0"

    try:
        sylvester(8.0)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "The input value of [n=8.0] is not an integer"