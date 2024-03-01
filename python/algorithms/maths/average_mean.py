from typing import List

def mean(nums: List[float]) -> float:
    if not nums:
        raise ValueError("List is empty")
    return sum(nums) / len(nums)