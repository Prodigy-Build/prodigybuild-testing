from typing import List
from random import randint

def test_max_sum_in_array():
    arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
    k = 4
    assert max_sum_in_array(arr, k) == 24

    k = 10
    try:
        max_sum_in_array(arr, k)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    arr = [1, 4, 2, 10, 2, 13, 1, 0, 2]
    k = 4
    assert max_sum_in_array(arr, k) == 27

    # Additional test cases
    arr = [1, 2, 3, 4, 5]
    k = 2
    assert max_sum_in_array(arr, k) == 9

    arr = [1, 2, 3, 4, 5]
    k = 5
    assert max_sum_in_array(arr, k) == 15

    arr = [1, 2, 3, 4, 5]
    k = 6
    try:
        max_sum_in_array(arr, k)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    arr = []
    k = 3
    try:
        max_sum_in_array(arr, k)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    arr = [1, 2, 3, 4, 5]
    k = -1
    try:
        max_sum_in_array(arr, k)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    arr = [1, 2, 3, 4, 5]
    k = 0
    try:
        max_sum_in_array(arr, k)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    # Test with large array and k
    arr = [randint(-1000, 1000) for i in range(1000)]
    k = 100
    assert max_sum_in_array(arr, k) == max_sum_in_array_brute_force(arr, k)

    print("All test cases pass")

test_max_sum_in_array()