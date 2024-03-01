from typing import List, Union

def median(nums: List[Union[int, float]]) -> Union[int, float]:
    sorted_list = sorted(nums)
    length = len(sorted_list)
    mid_index = length >> 1
    return (
        (sorted_list[mid_index] + sorted_list[mid_index - 1]) / 2
        if length % 2 == 0
        else sorted_list[mid_index]
    )

def test_median():
    assert median([0]) == 0
    assert median([4, 1, 3, 2]) == 2.5
    assert median([2, 70, 6, 50, 20, 8, 4]) == 8

test_median()