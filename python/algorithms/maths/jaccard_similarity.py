def test_jaccard_similarity():
    set_a = {'a', 'b', 'c', 'd', 'e'}
    set_b = {'c', 'd', 'e', 'f', 'h', 'i'}
    assert jaccard_similarity(set_a, set_b) == 0.375

    assert jaccard_similarity(set_a, set_a) == 1.0

    assert jaccard_similarity(set_a, set_a, True) == 0.5

    set_a = ['a', 'b', 'c', 'd', 'e']
    set_b = ('c', 'd', 'e', 'f', 'h', 'i')
    assert jaccard_similarity(set_a, set_b) == 0.375

test_jaccard_similarity()