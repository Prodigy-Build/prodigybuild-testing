from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    chk_map = {}
    for index, val in enumerate(nums):
        compl = target - val
        if compl in chk_map:
            return [chk_map[compl], index]
        chk_map[val] = index
    return []