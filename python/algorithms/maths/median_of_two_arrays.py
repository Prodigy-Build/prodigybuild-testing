from typing import List

def median_of_two_arrays(nums1: List[float], nums2: List[float]) -> float:
    all_numbers = sorted(nums1 + nums2)
    div, mod = divmod(len(all_numbers), 2)
    if mod == 1:
        return all_numbers[div]
    else:
        return (all_numbers[div] + all_numbers[div - 1]) / 2