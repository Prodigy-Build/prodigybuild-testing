def test_permute():
    assert permute([1, 2, 3]) == [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
    assert permute([1]) == [[1]]
    assert permute([]) == []

def test_permute2():
    assert permute2([1, 2, 3]) == [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
    assert permute2([1]) == [[1]]
    assert permute2([]) == []

test_permute()
test_permute2()