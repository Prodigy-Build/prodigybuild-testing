from typing import List
from random import randint

def max_sum_in_array(array: List[int], k: int) -> int:
    if len(array) < k or k < 0:
        raise ValueError("Invalid Input")
    max_sum = current_sum = sum(array[:k])
    for i in range(len(array) - k):
        current_sum = current_sum - array[i] + array[i + k]
        max_sum = max(max_sum, current_sum)
    return max_sum

def test_max_sum_in_array():
    arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
    k = 4
    assert max_sum_in_array(arr, k) == 24

    k = 10
    try:
        max_sum_in_array(arr, k)
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")

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
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")

    arr = []
    k = 2
    try:
        max_sum_in_array(arr, k)
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")

    arr = [1, 2, 3, 4, 5]
    k = -1
    try:
        max_sum_in_array(arr, k)
    except ValueError:
        pass
    else:
        raise AssertionError("Expected ValueError")

    arr = [randint(-1000, 1000) for i in range(100)]
    k = randint(0, 110)
    max_sum_in_array(arr, k)

test_max_sum_in_array()