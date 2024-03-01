def test_fermat_little_theorem():
    assert binary_exponentiation(2, 0, 5) == 1
    assert binary_exponentiation(2, 1, 5) == 2
    assert binary_exponentiation(2, 2, 5) == 4
    assert binary_exponentiation(2, 3, 5) == 3
    assert binary_exponentiation(2, 4, 5) == 1

    assert (1000000000 / 10) % 701 == (1000000000 * binary_exponentiation(10, 701 - 2, 701)) % 701
    assert (1000000000 / 10) % 701 == (1000000000 * 10 ** (701 - 2)) % 701