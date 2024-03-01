def test_extended_euclidean_algorithm():
    assert extended_euclidean_algorithm(1, 24) == (1, 0)
    assert extended_euclidean_algorithm(8, 14) == (2, -1)
    assert extended_euclidean_algorithm(240, 46) == (-9, 47)
    assert extended_euclidean_algorithm(1, -4) == (1, 0)
    assert extended_euclidean_algorithm(-2, -4) == (-1, 0)
    assert extended_euclidean_algorithm(0, -4) == (0, -1)
    assert extended_euclidean_algorithm(2, 0) == (1, 0)