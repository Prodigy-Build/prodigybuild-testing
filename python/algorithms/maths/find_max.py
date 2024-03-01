from typing import List, Union

def find_max(nums: List[Union[int, float]]) -> Union[int, float]:
    if len(nums) == 0:
        raise ValueError("find_max() arg is an empty sequence")
    max_num = nums[0]
    for x in nums:
        if x > max_num:
            max_num = x
    return max_num