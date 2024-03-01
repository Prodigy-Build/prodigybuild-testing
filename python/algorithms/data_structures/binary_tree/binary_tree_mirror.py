def test_binary_tree_mirror():
    assert binary_tree_mirror({ 1: [2,3], 2: [4,5], 3: [6,7], 7: [8,9]}, 1) == {1: [3, 2], 2: [5, 4], 3: [7, 6], 7: [9, 8]}
    assert binary_tree_mirror({ 1: [2,3], 2: [4,5], 3: [6,7], 4: [10,11]}, 1) == {1: [3, 2], 2: [5, 4], 3: [7, 6], 4: [11, 10]}
    try:
        binary_tree_mirror({ 1: [2,3], 2: [4,5], 3: [6,7], 4: [10,11]}, 5)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "root 5 is not present in the binary_tree"
    try:
        binary_tree_mirror({}, 5)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "binary tree cannot be empty"