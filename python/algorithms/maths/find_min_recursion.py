from typing import List, Union

def find_min(nums: List[Union[int, float]], left: int, right: int) -> Union[int, float]:
    if len(nums) == 0:
        raise ValueError("find_min() arg is an empty sequence")
    if (
        left >= len(nums)
        or left < -len(nums)
        or right >= len(nums)
        or right < -len(nums)
    ):
        raise IndexError("list index out of range")
    if left == right:
        return nums[left]
    mid = (left + right) >> 1
    left_min = find_min(nums, left, mid)
    right_min = find_min(nums, mid + 1, right)
    return left_min if left_min <= right_min else right_min